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

#include "window_manager.h"

#include "app_window_click_glue.h"
#include "app_window_stack.h"
#include "window.h"
#include "window_stack_private.h"

#include "kernel/pebble_tasks.h"
#include "kernel/ui/modals/modal_manager.h"
#include "process_state/app_state/app_state.h"
#include "system/logging.h"
#include "system/passert.h"

typedef bool (*ModalWindowPredicate)(Window *window);

bool window_manager_is_app_window(Window *window) {
  PBL_ASSERTN(window && window->parent_window_stack);
  WindowStack *app_window_stack = app_state_get_window_stack();
  return (window->parent_window_stack == app_window_stack);
}

static bool prv_is_app_or_modal_predicate(ModalWindowPredicate callback, Window *window) {
  if (!(window && window->parent_window_stack)) {
    return false;
  } else if (window_manager_is_app_window(window)) {
    return (window == app_window_stack_get_top_window());
  }
  return callback(window);
}

bool window_manager_is_window_visible(Window *window) {
  return prv_is_app_or_modal_predicate(modal_manager_is_window_visible, window);
}

bool window_manager_is_window_focused(Window *window) {
  return prv_is_app_or_modal_predicate(modal_manager_is_window_focused, window);
}

Window *window_manager_get_top_window(void) {
  if (pebble_task_get_current() == PebbleTask_App) {
    return app_window_stack_get_top_window();
  }
  return modal_manager_get_top_window();
}

WindowStack *window_manager_get_window_stack(ModalPriority priority) {
  if (pebble_task_get_current() == PebbleTask_App) {
    return app_state_get_window_stack();
  }
  return modal_manager_get_window_stack(priority);
}

ClickManager *window_manager_get_window_click_manager(Window *window) {
  if (window_manager_is_app_window(window)) {
    return app_state_get_click_manager();
  }
  return modal_manager_get_click_manager();
}
