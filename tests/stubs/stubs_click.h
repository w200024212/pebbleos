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

#pragma once

#include "applib/ui/click.h"
#include "applib/ui/click_internal.h"
#include "applib/ui/window.h"

#include "util/attributes.h"

WEAK ButtonId click_recognizer_get_button_id(ClickRecognizerRef recognizer) {
  return 0;
}

WEAK void click_recognizer_handle_button_up(ClickRecognizer *recognizer) {
  return;
}

WEAK void click_recognizer_handle_button_down(ClickRecognizer *recognizer) {
  return;
}

WEAK uint8_t click_number_of_clicks_counted(ClickRecognizerRef recognizer) {
  return 0;
}

WEAK bool click_recognizer_is_held_down(ClickRecognizerRef recognizer) {
  return false;
}

WEAK bool click_recognizer_is_repeating(ClickRecognizerRef recognizer) {
  return false;
}

WEAK void app_click_config_setup_with_window(ClickManager *click_manager, Window *window) {}
