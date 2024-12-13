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

#include "applib/ui/dialogs/confirmation_dialog.h"

ConfirmationDialog *confirmation_dialog_create(const char *dialog_name) {
  return NULL;
}

Dialog *confirmation_dialog_get_dialog(ConfirmationDialog *confirmation_dialog) {
  return NULL;
}

ActionBarLayer *confirmation_dialog_get_action_bar(ConfirmationDialog *confirmation_dialog) {
  return NULL;
}

void confirmation_dialog_set_click_config_provider(ConfirmationDialog *confirmation_dialog,
                                                   ClickConfigProvider click_config_provider) {}

void confirmation_dialog_push(ConfirmationDialog *confirmation_dialog, WindowStack *window_stack) {}

void app_confirmation_dialog_push(ConfirmationDialog *confirmation_dialog) {}

void confirmation_dialog_pop(ConfirmationDialog *confirmation_dialog) {}
