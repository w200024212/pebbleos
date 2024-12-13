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

#include "applib/graphics/perimeter.h"
#include "applib/ui/dialogs/dialog.h"
#include "applib/ui/window_stack.h"

//! Simple dialogs just contain a large icon and some text.
//! @internal
typedef struct SimpleDialog {
  Dialog dialog;
  bool buttons_disabled;
  bool icon_static;
} SimpleDialog;

//! Creates a new SimpleDialog on the heap.
//! @param dialog_name The debug name to give the dialog
//! @return Pointer to a \ref SimpleDialog
SimpleDialog *simple_dialog_create(const char *dialog_name);

//! @internal
//! @param simple_dialog Pointer to a \ref SimpleDialog to initialize
//! @param dialog_name The debug name to give the dialog
void simple_dialog_init(SimpleDialog *simple_dialog, const char *dialog_name);

//! Retrieves the internal Dialog object from the SimpleDialog.
//! @param simple_dialog Pointer to a \ref SimpleDialog whom's dialog to retrieve
//! @return pointer to the underlying dialog of the \ref SimpleDialog
Dialog *simple_dialog_get_dialog(SimpleDialog *simple_dialog);

//! Push the \ref SimpleDialog onto the given window stack.
//! @param simple_dialog Pointer to a \ref SimpleDialog to push onto the window stack
//! @param window_stack Pointer to a \ref WindowStack to push the dialog onto
void simple_dialog_push(SimpleDialog *simple_dialog, WindowStack *window_stack);

//! Wrapper to call \ref simple_dialog_push() for an app
//! @param simple_dialog Pointer to a \ref SimpleDialog to push onto the app's window stack
//! @note: Put a better comment here before exporting
void app_simple_dialog_push(SimpleDialog *simple_dialog);

//! Disables buttons for a \ref SimpleDialog. Usually used in conjunction with
//! \ref dialog_set_timeout()
//! @param simple_dialog Pointer to a \ref SimpleDialog
//! @param enabled Boolean expressing whether buttons should be enabled for the dialog
void simple_dialog_set_buttons_enabled(SimpleDialog *simple_dialog, bool enabled);

//! Sets whether the dialog icon is animated
//! @param simple_dialog Pointer to a \ref SimpleDialog
//! @param animated Whether the icon should animate or not
void simple_dialog_set_icon_animated(SimpleDialog *simple_dialog, bool animated);

bool simple_dialog_does_text_fit(const char *text, GSize window_size,
                                 GSize icon_size, bool has_status_bar);
