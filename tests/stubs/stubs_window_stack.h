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

#include "applib/ui/window_stack.h"

void window_stack_push(WindowStack *window_stack, Window *window, bool animated) { }

bool window_stack_remove(Window *window, bool animated) {
  return false;
}

void window_stack_pop_all(WindowStack *window_stack, bool animated) { }

void window_stack_insert_next(WindowStack *window_stack, Window *window) { }

bool window_stack_is_animating_with_fixed_status_bar(WindowStack *window_stack) {
  return false;
}

bool window_stack_contains_window(WindowStack *window_stack, Window *window) {
  return false;
}

bool window_transition_context_has_legacy_window_to(WindowStack *stack, Window *window){
  return false;
}

bool app_window_stack_remove(Window *window, bool animated) {
  return false;
}
