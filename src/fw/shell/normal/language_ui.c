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

#include "language_ui.h"

#include <stdio.h>

#include "applib/ui/dialogs/simple_dialog.h"
#include "kernel/event_loop.h"
#include "kernel/ui/modals/modal_manager.h"
#include "resource/resource_ids.auto.h"
#include "services/common/i18n/i18n.h"
#include "shell/normal/watchface.h"

static void prv_push_language_changed_dialog(void *data) {
  const char *lang_name = (const char *)data;
  SimpleDialog *simple_dialog = simple_dialog_create("LangFileChanged");
  Dialog *dialog = simple_dialog_get_dialog(simple_dialog);
  dialog_set_text(dialog, lang_name);
  dialog_set_icon(dialog, RESOURCE_ID_GENERIC_CONFIRMATION_LARGE);
  dialog_set_background_color(dialog, GColorJaegerGreen);
  dialog_set_timeout(dialog, DIALOG_TIMEOUT_DEFAULT);
  simple_dialog_push(simple_dialog, modal_manager_get_window_stack(ModalPriorityAlert));
  // after dialog closes, launch the watchface
  watchface_launch_default(NULL);
}

void language_ui_display_changed(const char *lang_name) {
  launcher_task_add_callback(prv_push_language_changed_dialog, (void *)lang_name);
}
