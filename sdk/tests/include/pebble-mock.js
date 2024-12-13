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
/* eslint no-console: 0 */

// Constructor to build a mock for the global Pebble object:
module.exports = function() {
  const simple = require('simple-mock');
  const assert = require('assert');

  var eventHandlers = {
    appmessage: [],
    ready: []
  };

  simple.mock(this, 'addEventListener', (event_name, handler) => {
    assert(event_name in eventHandlers, '\'' + event_name + '\' not known');
    eventHandlers[event_name].push(handler);
  });

  simple.mock(this, 'handleEvent', (event) => {
    assert(event.name in eventHandlers, '\'' + event.name + '\' not known');
    for (let handler of eventHandlers[event.name]) {
      handler(event);
    }
  });

  simple.mock(this, 'sendAppMessage', (msg, complCb, errCb) => {
    console.log(
      'sendAppMessage: ' + msg + ' complCb: ' + complCb + ' errCb: ' + errCb);
    if (complCb) {
      complCb(msg);
    }
  });
};
