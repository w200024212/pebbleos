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

#include "applib/ui/action_bar_layer.h"
#include "applib/ui/dialogs/dialog.h"
#include "applib/ui/window_stack.h"

typedef struct WorkoutDialog {
  Dialog dialog;
  ActionBarLayer action_bar;
  GBitmap confirm_icon;
  GBitmap decline_icon;
  TextLayer subtext_layer;
  char *subtext_buffer;
  bool hide_action_bar;
} WorkoutDialog;

void workout_dialog_init(WorkoutDialog *workout_dialog, const char *dialog_name);

WorkoutDialog *workout_dialog_create(const char *dialog_name);

Dialog *workout_dialog_get_dialog(WorkoutDialog *workout_dialog);

ActionBarLayer *workout_dialog_get_action_bar(WorkoutDialog *workout_dialog);

void workout_dialog_set_click_config_provider(WorkoutDialog *workout_dialog,
                                              ClickConfigProvider click_config_provider);

void workout_dialog_set_click_config_context(WorkoutDialog *workout_dialog, void *context);

void workout_dialog_push(WorkoutDialog *workout_dialog, WindowStack *window_stack);

void app_workout_dialog_push(WorkoutDialog *workout_dialog);

void workout_dialog_pop(WorkoutDialog *workout_dialog);

void workout_dialog_set_text(WorkoutDialog *workout_dialog, const char *text);

void workout_dialog_set_subtext(WorkoutDialog *workout_dialog, const char *text);

void workout_dialog_set_action_bar_hidden(WorkoutDialog *workout_dialog, bool should_hide);
