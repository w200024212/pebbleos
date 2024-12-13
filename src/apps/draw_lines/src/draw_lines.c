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

#include <pebble.h>

// Access profiler functions.
extern void __profiler_init(void);
extern void __profiler_print_stats(void);
extern void __profiler_start(void);
extern void __profiler_stop(void);

static Window *window;

typedef enum {
  LineDirection_Horizontal,
  LineDirection_Vertical,
  LineDirection_Diagonal,
} LineDirection;

static void prv_draw_lines(GContext *ctx, GRect bounds, uint32_t num_lines, LineDirection dir) {
  GPoint start, end;
  switch (dir) {
    case LineDirection_Horizontal:
      APP_LOG(APP_LOG_LEVEL_INFO, "Horizontal lines");
      start = GPoint(bounds.origin.x, bounds.size.h / 2);
      end = GPoint(bounds.size.w, bounds.size.h / 2);
      break;
    case LineDirection_Vertical:
      APP_LOG(APP_LOG_LEVEL_INFO, "Vertical lines");
      start = GPoint(bounds.size.w / 2, bounds.origin.y);
      end = GPoint(bounds.size.w / 2, bounds.size.h);
      break;
    case LineDirection_Diagonal:
      APP_LOG(APP_LOG_LEVEL_INFO, "Diagonal lines");
      start = bounds.origin;
      end = GPoint(bounds.size.w, bounds.size.h);
      break;
  }

  __profiler_start();
  for (uint32_t i = 0; i < num_lines; ++i) {
    graphics_draw_line(ctx, start, end);
  }
  __profiler_stop();
  __profiler_print_stats();
}

static void prv_update_proc(Layer *layer, GContext *ctx) {
  static const uint32_t NUM_LINES_TO_DRAW = 10000;
  GRect bounds = layer_get_bounds(layer);

  prv_draw_lines(ctx, bounds, NUM_LINES_TO_DRAW, LineDirection_Vertical);
  prv_draw_lines(ctx, bounds, NUM_LINES_TO_DRAW, LineDirection_Horizontal);
  prv_draw_lines(ctx, bounds, NUM_LINES_TO_DRAW, LineDirection_Diagonal);
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  layer_set_update_proc(window_layer, prv_update_proc);
}

static void init(void) {
  __profiler_init();
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
  });
  window_stack_push(window, true);
}

static void deinit(void) {
  window_destroy(window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
