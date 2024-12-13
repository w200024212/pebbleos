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

//! A ConfirmationDialog is a wrapper around an ActionableDialog implementing
//! the common features provided by a confirmation window.  The user specifies
//! callbacks for confirm/decline and can also override the back button behaviour.
#pragma once

#include "applib/ui/action_bar_layer.h"
#include "applib/ui/click.h"
#include "applib/ui/dialogs/dialog.h"
#include "applib/ui/window_stack.h"

typedef struct ConfirmationDialog ConfirmationDialog;

//! Creates a ConfirmationDialog on the heap.
//! @param dialog_name The debug name to give the created dialog
//! @return Pointer to the created \ref ConfirmationDialog
ConfirmationDialog *confirmation_dialog_create(const char *dialog_name);

//! Retrieves the internal Dialog object from the ConfirmationDialog.
//! @param confirmation_dialog Pointer to a \ref ConfirmationDialog whom's dialog to get
//! @return Pointer to the underlying \ref Dialog
Dialog *confirmation_dialog_get_dialog(ConfirmationDialog *confirmation_dialog);

//! Retrieves the internal ActionBarLayer object from the ConfirmationDialog.
//! @param confirmation_dialog Pointer to a \ref ConfirmationDialog whom's
//!     \ref ActionBarLayer to get
//! @return \ref ActionBarLayer
ActionBarLayer *confirmation_dialog_get_action_bar(ConfirmationDialog *confirmation_dialog);

//! Sets the click ClickConfigProvider for the ConfirmationDialog.
//! Passes the ConfirmationDialog as the context to the click handlers.
//! @param confirmation_dialog Pointer to a \ref ConfirmationDialog to which to set
//! @param click_config_provider The \ref ClickConfigProvider to set
void confirmation_dialog_set_click_config_provider(ConfirmationDialog *confirmation_dialog,
                                                   ClickConfigProvider click_config_provider);

//! Pushes the ConfirmationDialog onto the given window stack
//! @param confirmation_dialog Pointer to a \ref ConfirmationDialog to push
//! @param window_stack Pointer to a \ref WindowStack to push the dialog to
void confirmation_dialog_push(ConfirmationDialog *confirmation_dialog, WindowStack *window_stack);

//! Wrapper for an app to call \ref confirmation_dialog_push()
//! @param confirmation_dialog Pointer to a \ref ConfirmationDialog to push to
//!     the app's window stack
//! @note: Put a better comment here before exporting
void app_confirmation_dialog_push(ConfirmationDialog *confirmation_dialog);

//! Pops the ConfirmationDialog from the window stack.
//! @param confirmation_dialog Pointer to a \ref ConfirmationDialog to pop from its window stack
void confirmation_dialog_pop(ConfirmationDialog *confirmation_dialog);
