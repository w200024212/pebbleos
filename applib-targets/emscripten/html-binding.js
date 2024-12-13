/*

  Copyright © 2015-2016 Pebble Technology Corp.,
  All Rights Reserved. http://pebble.github.io/rockyjs/LICENSE

  This describes functionality to bind the Rocky Simulator to an HTML canvas
  element. This file is included into the Emscripten output using --post-js,
  as such it will end up in body of the RockySimulator(options) constructor.

 */

if (typeof(Module) === 'undefined') {
  var Module = {};
}

Module.bindCanvas = function(canvas) {
  // in a future version, these values should adapt automatically
  // also, we want the ability to create framebuffers of larger sizes
  var canvasW = canvas.width;
  var canvasH = canvas.height;
  var framebufferW = 144;
  var framebufferH = 168;

  // scale gives us the ability to do a nearest-neighbor scaling
  var scale = options.scale ||
              Math.min(canvasW / framebufferW, canvasH / framebufferH);

  // pixel access to read (framebuffer) and write to (canvas)
  var canvasCtx = canvas.getContext('2d');
  var canvasPixelData = canvasCtx.createImageData(canvasW, canvasH);
  var canvasPixels = canvasPixelData.data;
  var framebufferPixelPTR = Module.ccall(
    'emx_graphics_get_pixels', 'number', []
  );

  var isRenderRequested = false;
  var copyFrameBufferToCanvas = function(timestamp) {
    console.log('copying pixels...');
    isRenderRequested = false;
    var framebufferPixels = new Uint8Array(Module.HEAPU8.buffer,
                                           framebufferPixelPTR,
                                           framebufferW * framebufferH);
    // renders current state of the framebuffer to the bound canvas
    // respecting the passed scale
    for (var y = 0; y < canvasH; y++) {
      var pebbleY = (y / scale) >> 0;
      if (pebbleY >= framebufferH) {
        break;
      }
      for (var x = 0; x < canvasW; x++) {
        var pebbleX = (x / scale) >> 0;
        if (pebbleX >= framebufferW) {
          break;
        }
        var pebbleOffset = pebbleY * framebufferW + pebbleX;
        var in_values = framebufferPixels[pebbleOffset];
        var r = ((in_values >> 4) & 0x3) * 85;
        var g = ((in_values >> 2) & 0x3) * 85;
        var b = ((in_values >> 0) & 0x3) * 85;
        var canvasOffset = (y * canvasW + x) * 4;
        canvasPixels[canvasOffset + 0] = r;
        canvasPixels[canvasOffset + 1] = g;
        canvasPixels[canvasOffset + 2] = b;
        canvasPixels[canvasOffset + 3] = 255;
      }
    }
    canvasCtx.putImageData(canvasPixelData, 0, 0);
  };

  Module.frameBufferMarkDirty = function() {
    if (isRenderRequested) {
      return;
    }
    console.log('request render');
    isRenderRequested = true;
    window.requestAnimationFrame(copyFrameBufferToCanvas);
  }
};

// Apply `options` from the RockySimulator(options) constructor:
if (typeof(options) !== 'undefined' && options.canvas) {
  Module.bindCanvas(options.canvas);
}
