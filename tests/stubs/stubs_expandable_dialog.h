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

#include "stubs_dialog.h"
#include "applib/ui/window_stack.h"
#include "applib/ui/window_stack_private.h"


typedef struct ExpandableDialog {
  Dialog dialog;
} ExpandableDialog;

ExpandableDialog *expandable_dialog_create(const char *dialog_name) {
  return NULL;
}

ExpandableDialog *expandable_dialog_create_with_params(const char *dialog_name, uint32_t icon,
                                                       const char *text, GColor text_color,
                                                       GColor background_color,
                                                       DialogCallbacks *callbacks,
                                                       uint32_t select_icon,
                                                       ClickHandler select_click_handler) {
  return NULL;
}
Dialog *expandable_dialog_get_dialog(ExpandableDialog *expandable_dialog) {
  if (expandable_dialog == NULL) {
    return NULL;
  }
  return &expandable_dialog->dialog;
}

void expandable_dialog_push(ExpandableDialog *expandable_dialog, WindowStack *window_stack) {
  return;
}

void app_expandable_dialog_push(ExpandableDialog *expandable_dialog) {
}

void expandable_dialog_pop(ExpandableDialog *expandable_dialog) {
  return;
}

void expandable_dialog_set_select_action(ExpandableDialog *expandable_dialog,
                                         uint32_t resource_id,
                                         ClickHandler select_click_handler) {
  return;
}

void expandable_dialog_close_cb(ClickRecognizerRef recognizer, void *e_dialog) {
  return;
}

void expandable_dialog_show_action_bar(ExpandableDialog *expandable_dialog,
                                       bool show_action_bar) {
  return;
}
