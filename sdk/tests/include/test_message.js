/**
 * Copyright 2024 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* eslint-env mocha */
/* eslint func-names: 0 */

const assert = require('assert');
const unroll = require('unroll');
unroll.use(it);

// Override setTimeout() to fire immediately:
var origSetTimeout = setTimeout;
setTimeout = function(f, t) {
  origSetTimeout(f.bind(undefined), 0);
};

describe('Pebble', () => {

  var mockPebble;

  const simulateReceivingAppMessageEvent = (payload) => {
    const appMessageEvent = {
      name: 'appmessage',
      payload: payload
    };
    global.Pebble.handleEvent(appMessageEvent);
  };

  const enterSessionOpen = () => {
    global.Pebble.handleEvent({ name : "ready" });
    var data = new Uint8Array(6);
    data[0] = 1;
    data[1] = 3;
    data[2] = 0;
    data[3] = 155;
    data[4] = 0;
    data[5] = 155;
    simulateReceivingAppMessageEvent({ 'ControlKeyResetComplete' : Array.from(data) });
    mockPebble.sendAppMessage.reset();
  };

  const createChunk = (offset, size, data) => {
    if (offset == 0) { // First msg
      var isFirst = (1 << 7);
      var n = size + 1;
    } else {
      var isFirst = 0;
      var n = offset;
    }
    var rv = [ (n) & 255,
               (n >> 8) & 255,
               (n >> 16) & 255,
               ((n >> 24) & ~(1 << 7)) | isFirst ];
    Array.prototype.push.apply(rv, data.slice(offset, offset + size));
    if (offset + size == data.length) {
      rv.push(0);
    }
    return { "ControlKeyChunk" : rv };
  };

  const simulateReceivingPostMessageChunk = () => {
    var data = '{ "msg_num" : 0 }'.split('').map(function(x) { return x.charCodeAt(0); });
    var chunk = createChunk(0, data.length, data);
    simulateReceivingAppMessageEvent(chunk);
  };

  beforeEach(() => {
    // Create a new mock for the Pebble global object for each test:
    const PebbleMockConstructor = require('./pebble-mock.js');
    global.Pebble = new PebbleMockConstructor();

    // Keep a reference to the mock that will be "wrapped" as soon as _pkjs_message_wrapper.js
    // is loaded...
    mockPebble = global.Pebble;

    // Reload it to 'patch' the Pebble object:
    const message_js_path = '../../include/_pkjs_message_wrapper.js';
    delete require.cache[require.resolve(message_js_path)];
    require(message_js_path);
    enterSessionOpen();
  });


  /****************************************************************************
   * Message Encoding
   ***************************************************************************/

  describe('interprets received postMessage API data as UTF-8', () => {
    unroll('interprets #utf8_data as #result', (done, fixture) => {
      global.Pebble.on('message', (event) => {
        assert.equal(event.type, 'message');
        assert.equal(event.data, fixture.result);
        done();
      });

      const payload = createChunk(0, fixture.utf8_data.length, fixture.utf8_data);

      if (fixture.result instanceof Error) {
        assert.throws(() => {
          simulateReceivingAppMessageEvent(payload);
        }, typeof(fixture.result), fixture.result.message);
        done();
      } else {
        simulateReceivingAppMessageEvent(payload);
      }

    }, [
        ['utf8_data', 'result'],
        // empty string:
        [[34, 34], ''],
        // Pile of Poo, in double quotes:
        [[34, 240, 159, 146, 169,34], '💩'],
        // Surrogates are illegal in UTF-8:
        [[34, 0xED, 0xA0, 0xB5, 0xED, 0xBC, 0x80, 34], Error('Lone surrogate U+D835 is not a scalar value')],
        // 2-byte code point, in double quotes:
        [[34, 196, 145, 34], '\u0111'],
        // 3-byte codepoint, in double quotes:
        [[34, 0xE0, 0xA0, 0x95, 34], '\u0815']
    ]);
  });

  describe('encodes sent postMessage API data as UTF-8', () => {
    unroll('encodes #input as #utf8_data', (done, fixture) => {

      global.Pebble.postMessage(fixture.input);
      assert.equal(mockPebble.sendAppMessage.callCount, 1);
      const lastAppMessage = mockPebble.sendAppMessage.lastCall.args[0];
      assert.deepEqual(lastAppMessage['ControlKeyChunk'].slice(4), fixture.utf8_data);
      done();

    }, [
        ['input', 'utf8_data'],
        // empty string:
        ['', [34, 34, 0]],
        // Pile of Poo, in double quotes:
        ['💩', [34, 240, 159, 146, 169, 34, 0]],
        // 2-byte code point, in double quotes:
        ['\u0111', [34, 196, 145, 34, 0]],
        // 3-byte codepoint, in double quotes:
        ['\u0815', [34, 0xE0, 0xA0, 0x95, 34, 0]]
    ]);
  });


  /****************************************************************************
   * Message Handlers
   ***************************************************************************/

  describe('Ensure that AppMessage is blocked', () => {
    it('tries to register a Pebble.on("appmessage") handler', (done) => {
      assert.throws(() => {
          global.Pebble.on('appmessage', (e) => {
            assert(0, "Should not have been called");
          });
        }, /not supported/);

      // If this results in our callback being called, we'll throw an Error().
      simulateReceivingAppMessageEvent({ 'KEY' : 'DATA' });
      done();
    });
    it('tries to Pebble.addEventListener("appmessage")', (done) => {
      assert.throws(() => {
          global.Pebble.addEventListener('appmessage', (e) => {
            // This will be thrown if the eventlistener was registered
            assert(0, "Should not have been called");
          });
        }, /not supported/);

      // If this results in our callback being called, we'll throw an Error().
      simulateReceivingAppMessageEvent({ 'KEY' : 'DATA' });
      done();
    });
    it('tries to call Pebble.sendAppMessage()', (done) => {
      assert.notStrictEqual(typeof global.Pebble.sendAppMessage, 'function');
      assert.equal(global.Pebble.sendAppMessage, undefined);
      done();
    });
  });

  describe('registers multiple message handlers', () => {
    unroll('registers #num_handlers handlers to receive #num_messages messages each', (done, fixture) => {
      var callback_count = 0;
      var handler = function(e) { ++callback_count; };

      for (var h = 0; h < fixture.num_handlers; ++h) {
        global.Pebble.on('message', handler);
      }
      for (var i = 0; i < fixture.num_messages; ++i) {
        simulateReceivingPostMessageChunk();
      }
      assert.equal(callback_count, fixture.num_handlers * fixture.num_messages);
      done();
    }, [
         [ 'num_handlers', 'num_messages' ],
         [ 1,              1              ],
         [ 2,              1              ],
         [ 3,              2              ],
    ]);
  });

  describe('registers multiple message handlers, unsubscribes one', () => {
    unroll('registers #num_handlers, then unregisters #num_unregister', (done, fixture) => {
      var callback_count = 0;
      var handler = function(e) { ++callback_count; };

      for (var h = 0; h < fixture.num_handlers; ++h) {
        global.Pebble.on('message', handler);
      }
      for (var u = 0; u < fixture.num_unregister; ++u) {
        global.Pebble.off('message', handler);
      }
      simulateReceivingPostMessageChunk();
      assert.equal(callback_count, fixture.num_handlers - fixture.num_unregister);
      done();
    }, [
         [ 'num_handlers', 'num_unregister' ],
         [ 4,               2               ],
         [ 10,              10              ],
    ]);
  });

  describe('call Pebble.off("message", handler) from within that event handler', () => {
    unroll('calling while #num_registered other handlers are registered', (done, fixture) => {
      var callback_count = 0;
      var handler = function(e) { ++callback_count; };
      var remove_handler = function(e) { ++callback_count; global.Pebble.off('message', remove_handler); }

      global.Pebble.on('message', remove_handler);
      for (var i = 0; i < fixture.num_registered; ++i) {
        global.Pebble.on('message', handler);
      }
      simulateReceivingPostMessageChunk();
      assert.equal(callback_count, fixture.num_registered + 1);

      // Now that the remove_handler has been removed, send another and make
      // sure that we have one less called.
      callback_count = 0;
      simulateReceivingPostMessageChunk();
      assert.equal(callback_count, fixture.num_registered);
      done();
    }, [
         [ 'num_registered' ],
         [ 0 ],
         [ 1 ],
         [ 10 ],
    ]);
  });


  /****************************************************************************
   * postmessageerror event
   ***************************************************************************/

  describe('postmessageerror Event', () => {
    it('event.data is set to the object that was attempted to be sent', (done) => {
      global.Pebble.handleEvent({ name : "ready" });
      mockPebble.sendAppMessage.reset();

      global.Pebble.on('postmessageerror', function(e) {
        assert.deepEqual(e.data, {b: 'c'});
        done();
      });

      var a = { b: 'c' };
      global.Pebble.postMessage(a);
      a.b = 'd';  // modify to test that a copy of 'a' is sent
    });
  });


  /****************************************************************************
   * postmessageconnected / postmessagedisconnected event
   ***************************************************************************/

  describe('Connection Events', () => {
    unroll('postmessageconnected. Start connected: #start_connected', (done, fixture) => {
      var connected_call_count = 0;

      if (!fixture.start_connected) {
        // Disconnect
        global.Pebble.handleEvent({ name : "ready" });
      }
      global.Pebble.on('postmessageconnected', function(e) {
        assert.equal(e.type, 'postmessageconnected');
        ++connected_call_count;
      });

      enterSessionOpen(); // establish connection

      if (fixture.start_connected) {
        assert.equal(connected_call_count, 2);
      } else {
        assert.equal(connected_call_count, 1);
      }

      done();
    }, [
      [ 'start_connected' ],
      [ true,             ],
      [ false,            ],
    ]);

    unroll('postmessagedisconnected. Start disconnected: #start_disconnected', (done, fixture) => {
      var disconnected_call_count = 0;

      if (fixture.start_disconnected) {
        // Disconnect
        global.Pebble.handleEvent({ name : "ready" });
      }
      global.Pebble.on('postmessagedisconnected', function(e) {
        assert.equal(e.type, 'postmessagedisconnected');
        ++disconnected_call_count;
      });

      if (fixture.start_disconnected) {
        // Need to establish a connection before we can disconnect
        enterSessionOpen();
      }

      global.Pebble.handleEvent({ name : "ready" }); // Disconnect again

      if (fixture.start_disconnected) {
        assert.equal(disconnected_call_count, 2);
      } else {
        assert.equal(disconnected_call_count, 1);
      }

      done();
    }, [
      [ 'start_disconnected' ],
      [ true,                ],
      [ false,               ],
    ]);
  });

  /****************************************************************************
   * Control Layer
   ***************************************************************************/

  describe('Control Layer', () => {
    it('Ready message => ResetRequest', (done) => {
      global.Pebble.handleEvent({ name : "ready" });

      assert.equal(mockPebble.sendAppMessage.callCount, 1);
      assert('ControlKeyResetRequest' in mockPebble.sendAppMessage.lastCall.args[0]);
      done();
    });
    it ('Disconnected => AwaitingResetCompleteLocalInitiated => SessionOpen', (done) => {
      global.Pebble.handleEvent({ name : "ready" });
      mockPebble.sendAppMessage.reset();

      var data = new Uint8Array(6);
      data[0] = 1;
      data[1] = 3;
      data[2] = 0;
      data[3] = 155;
      data[4] = 0;
      data[5] = 155;
      simulateReceivingAppMessageEvent({ 'ControlKeyResetComplete' : Array.from(data) });

      assert.equal(mockPebble.sendAppMessage.callCount, 1);
      assert('ControlKeyResetComplete' in mockPebble.sendAppMessage.lastCall.args[0]);
      done();
    });
    it ('Disconnected => AwaitingResetCompleteLocalInitiated => UnsupportedError', (done) => {
      global.Pebble.handleEvent({ name : "ready" });
      mockPebble.sendAppMessage.reset();

      var data = new Uint8Array(6);
      data[0] = 155; // Unsupported min version
      data[1] = 156; // Unsupported max version
      data[2] = 0;
      data[3] = 155;
      data[4] = 0;
      data[5] = 155;
      simulateReceivingAppMessageEvent({ 'ControlKeyResetComplete' : Array.from(data) });

      assert.equal(mockPebble.sendAppMessage.callCount, 1);
      assert('ControlKeyUnsupportedError' in mockPebble.sendAppMessage.lastCall.args[0]);
      done();
    });
    it ('SessionOpen => AwaitingResetCompleteRemoteInitiated => UnsupportedError => Error', (done) => {
      simulateReceivingAppMessageEvent({ 'ControlKeyResetRequest' : 0 });
      assert.equal(mockPebble.sendAppMessage.callCount, 1);
      assert('ControlKeyResetComplete' in mockPebble.sendAppMessage.lastCall.args[0]);

      try {
        simulateReceivingAppMessageEvent({ 'ControlKeyUnsupportedError' : "Test Error" });
      } catch (e) {
        assert.equal("Error: Unsupported protocol error: Test Error", e.toString());
      }
      done();
    });
    it ('Retry sending control message, check max retries.', (done) => {
      // override setTimeout
      setTimeout = function(fn, delay) {
        fn(); // Use a synchronous call here because we want to make sure that there
              // is a maximum of 3 callbacks. If we do these asynchronously,
              // there is no nice way to test this.
      }

      // Replace our sendAppMessage with one that will always call the error callback
      _mockSendAppMessage = mockPebble.sendAppMessage;
      mockPebble.sendAppMessage = function(msg, complCb, errCb) {
        _mockSendAppMessage(msg, undefined, errCb);
        errCb(msg);
      };
      simulateReceivingAppMessageEvent({ 'ControlKeyResetRequest' : 0 });

      // Should be called 1 + 3 retries, no more.
      assert.equal(_mockSendAppMessage.callCount, 4);
      done();
    });
    it('Retry sending control message, asynch', (done) => {
      // This test will fail due to timeout if retry isn't working correctly.

      var _setTimeout = setTimeout;
      setTimeout = function(fn, delay) {
        _setTimeout(fn, 0);
      }
      _mockSendAppMessage = mockPebble.sendAppMessage;
      mockPebble.sendAppMessage = function(msg, complCb, errCb) {
        _mockSendAppMessage(msg, undefined, errCb);
        if (_mockSendAppMessage.callCount == 4) {
          // 4 calls is 1 + 3 retries. We're done here
          done();
        } else {
          _setTimeout(errCb.bind(msg), 0);
        }
      };
      simulateReceivingAppMessageEvent({ 'ControlKeyResetRequest' : 0 });
    });
  });

  it('.postMessage(nonJSONable) should throw a TypeError', (done) => {
    var expectedMsg =
      "Argument at index 0 is not a JSON.stringify()-able object";
    assert.throws(
      () => { global.Pebble.postMessage(undefined); }, TypeError, expectedMsg);
    assert.throws(
      () => { global.Pebble.postMessage(() => {}); }, TypeError, expectedMsg);
    done()
  });
});
