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

static const int FPS_NO_PROBLEM = 10;
static const int FPS_NO_RESPONSE = 20;

#define FPS 80

static Window *window;

static void timed_update(void *data) {
  layer_mark_dirty(window_get_root_layer(window));
  app_timer_register(1000 / FPS, timed_update, NULL);
}

static void init(void) {
  window = window_create();

  Layer *window_layer = window_get_root_layer(window);

  GRect window_bounds = layer_get_bounds(window_layer);

  TextLayer *text_layer = text_layer_create(window_bounds);
  text_layer_set_text(text_layer, "Unplug and plug in the charger. You will see that the system cannot keep up with it.");
  layer_add_child(window_layer, text_layer_get_layer(text_layer));

  text_layer = text_layer_create((GRect) {{ 0, window_bounds.size.h / 2 }, window_bounds.size} );
  static char buffer[80];
  snprintf(buffer, sizeof(buffer), "FPS: %u", FPS);
  text_layer_set_text(text_layer, buffer);
  layer_add_child(window_layer, text_layer_get_layer(text_layer));

  window_stack_push(window, true);

  timed_update(NULL);
}

int main(void) {
  init();
  app_event_loop();
}

