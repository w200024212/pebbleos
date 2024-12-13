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

static Window *window;
static TextLayer *text_layer;

static char text_buffer[64];

static int s_counter = 3;

static void prv_update_text(void) {
  snprintf(text_buffer, sizeof(text_buffer), "Crashing in %d seconds", s_counter);
  text_layer_set_text(text_layer, text_buffer);
}

static void prv_execute_gibberish(void) {
  int32_t gibberish[] = { 0, 0, 0, 0 };
  int8_t* gibberish_ptr = (int8_t*) gibberish;

  ((void (*)(void))gibberish_ptr + 1)();
}

static void prv_timer_callback(void *data) {
  --s_counter;

  if (s_counter == 0) {
    prv_execute_gibberish();
  }

  prv_update_text();

  app_timer_register(1000, prv_timer_callback, 0);
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  text_layer = text_layer_create((GRect) { .origin = { 0, 72 }, .size = { bounds.size.w, 20 } });
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
  prv_update_text();
  layer_add_child(window_layer, text_layer_get_layer(text_layer));
}

static void window_unload(Window *window) {
  text_layer_destroy(text_layer);
}

static void init(void) {
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);

  app_timer_register(1000, prv_timer_callback, 0);
}

static void deinit(void) {
  window_destroy(window);
}

int main(void) {
  init();

  app_event_loop();
  deinit();
}
