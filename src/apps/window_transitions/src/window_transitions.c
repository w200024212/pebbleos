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

static bool s_next_window_fullscreen;

static void unload_handler(Window *window) {
  window_destroy(window);
}

static void push_window(void);

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  push_window();
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
}

static void push_window(void) {
  Window *window = window_create();
  window_set_fullscreen(window, s_next_window_fullscreen);
  window_set_window_handlers(window, (WindowHandlers) {
    .unload = unload_handler,
  });
  window_set_click_config_provider(window, click_config_provider);

  s_next_window_fullscreen = !s_next_window_fullscreen;

  window_stack_push(window, true);
}

int main(void) {
  push_window();

  app_event_loop();
}
