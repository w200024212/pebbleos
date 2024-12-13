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

#include "applib/ui/window_stack_private.h"
#include "kernel/ui/modals/modal_manager.h"
#include "util/attributes.h"

WindowStack *WEAK modal_manager_get_window_stack(ModalPriority priority) {
  return NULL;
}

Window *WEAK modal_manager_get_top_window(void) {
  return NULL;
}

ClickManager *WEAK modal_manager_get_click_manager(void) {
  return NULL;
}

void WEAK modal_manager_pop_all(void) {
  return;
}

bool WEAK modal_manager_get_enabled(void) {
  return true;
}

void WEAK modal_manager_set_enabled(bool enabled) {
  return;
}

ModalProperty WEAK modal_manager_get_properties(void) {
  return ModalPropertyDefault;
}

void modal_window_push(Window *window, ModalPriority priority, bool animated) { }
