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

typedef struct SimpleDialog {
  Dialog dialog;
} SimpleDialog;

SimpleDialog *simple_dialog_create(const char *dialog_name) {
  return NULL;
}

void simple_dialog_init(SimpleDialog *simple_dialog, const char *dialog_name) {
  return;
}

Dialog *simple_dialog_get_dialog(SimpleDialog *simple_dialog) {
  if (simple_dialog == NULL) {
    return NULL;
  }
  return &simple_dialog->dialog;
}

void simple_dialog_push(SimpleDialog *simple_dialog, WindowStack *window_stack) {
  return;
}

void app_simple_dialog_push(SimpleDialog *simple_dialog) {
}

bool simple_dialog_does_text_fit(const char *text, GSize window_size,
                                 GSize icon_size, bool has_status_bar) {
  return true;
}
