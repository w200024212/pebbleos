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

#include "applib/ui/click_internal.h"
#include "applib/ui/window.h"
#include "applib/ui/window_stack_private.h"
#include "util/attributes.h"

Window *WEAK window_manager_get_top_window(void) {
  return NULL;
}

WindowStack *WEAK window_manager_get_window_stack(void) {
  return NULL;
}

ClickManager *WEAK window_manager_get_window_click_manager(void) {
  return NULL;
}

bool window_manager_is_window_visible(Window *window) {
  return true;
}
