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

static TextLayer *s_text_launch_reason;
static TextLayer *s_text_instructions;
static Window *window;

static void prv_wakeup_handler(WakeupId id, int32_t reason) {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Woken up.");
}

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  wakeup_service_subscribe(prv_wakeup_handler);
  wakeup_schedule(time(NULL) + 5 , 1, false);
  window_stack_pop(true);
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
}

static char *get_launch_reason_str(void) {
  switch (launch_reason()) {
  case APP_LAUNCH_SYSTEM:
    return "SYSTEM";
  case APP_LAUNCH_USER:
    return "USER";
  case APP_LAUNCH_PHONE:
    return "PHONE";
  case APP_LAUNCH_WAKEUP:
    return "WAKEUP";
  case APP_LAUNCH_WORKER:
    return "WORKER";
  case APP_LAUNCH_QUICK_LAUNCH:
    return "QUICK LAUNCH";
  case APP_LAUNCH_TIMELINE_ACTION:
    return "TIMELINE ACTION";
  }
  return "ERROR";
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);

  s_text_launch_reason = text_layer_create(layer_get_frame(window_layer));
  char *reason = get_launch_reason_str();
  APP_LOG(APP_LOG_LEVEL_INFO, "Launch reason: %s", reason);
  text_layer_set_text(s_text_launch_reason, reason);
  layer_add_child(window_layer, text_layer_get_layer(s_text_launch_reason));

  GRect frame = layer_get_frame(window_layer);
  frame.origin = GPoint(0, 50);
  s_text_instructions = text_layer_create(frame);
  text_layer_set_text(s_text_instructions, "Press select to start 5s wakeup");
  layer_add_child(window_layer, text_layer_get_layer(s_text_instructions));
}

static void window_unload(Window *window) {
  text_layer_destroy(s_text_launch_reason);
  text_layer_destroy(s_text_instructions);
}

static void init(void) {
  window = window_create();
  window_set_click_config_provider(window, click_config_provider);
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);
}

static void deinit(void) {
  window_destroy(window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
