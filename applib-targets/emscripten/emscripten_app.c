/*
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

#include "emscripten_app.h"
#include "emscripten_graphics.h"
#include "emscripten_resources.h"
#include "emscripten_tick_timer_service.h"

#include "applib/app.h"
#include "applib/ui/app_window_stack.h"
#include "applib/rockyjs/api/rocky_api_graphics.h"

#include <emscripten/emscripten.h>

__attribute__((weak)) int app_main(void) {
  Window *window = window_create();
  app_window_stack_push(window, false);
  app_event_loop();
  return 0;
}

static void prv_event_loop(void) {
  Window *window = app_window_stack_get_top_window();
  if (window && window->is_render_scheduled) {
    GContext *ctx = rocky_api_graphics_get_gcontext();
    layer_render_tree(&window->layer, ctx);
    window->is_render_scheduled = false;
    EM_ASM(
      // Implemented by html-binding.js:
      if (Module.frameBufferMarkDirty) {
       Module.frameBufferMarkDirty()
      }
    );
  }
}

void emx_app_init(void) {
  emx_graphics_init();
  emx_resources_init();
  emx_tick_timer_service_init();
}

void emx_app_deinit(void) {
  emx_resources_deinit();
}

void emx_app_event_loop(void) {
  emscripten_set_main_loop(prv_event_loop,
                           0, /* using window.requestAnimationFrame() */
                           1  /* Simulate infinite loop */);
}

int main(int argc, char **argv) {
  emx_app_init();
  app_main();
  emx_app_deinit();

  return 0;
}
