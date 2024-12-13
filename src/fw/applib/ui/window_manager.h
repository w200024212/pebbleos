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

#include "kernel/ui/modals/modal_manager.h"
#include "window.h"
#include "window_stack.h"

//! @internal
//! Returns a boolean indicating whether or not the passed window resides
//! on an application window stack.  The passed window must not be NULL and must
//! have a non-null `.parent_window_stack` property.
//! @param window Pointer to the \ref Window to check
//! @returns Boolean indicating if the \ref Window resides on an app window stack
bool window_manager_is_app_window(Window *window);

//! @internal
//! Returns a boolean indicating if the passed window is currently visible for its
//! given context.  Note that this does not check if the window in question has focus.
//! This also does not determine whether an app window visibility is obstructed by a modal window.
//! @param window Pointer to the \ref Window to check
//! @returns Boolean indicating visibility
bool window_manager_is_window_visible(Window *window);

//! @internal
//! Returns a boolean indicating if the passed window is currently focused for its
//! given context. Note that this does not check if the window in question is visible.
//! This also does not determine whether an app window focus is obstructed by a modal window.
//! @param window Pointer to the \ref Window to check
//! @returns Boolean indicating focus
bool window_manager_is_window_focused(Window *window);

//! @internal
//! Returns the topmost window belonging to the current context.
//! @returns Pointer to a \ref Window
Window *window_manager_get_top_window(void);

//! @internal
//! Returns the window stack of the task. If the current task is KernelMain the stack of the
//! desired priority is given.
WindowStack *window_manager_get_window_stack(ModalPriority priority);

//! @internal
//! Returns the \ref ClickManager for the given window
//! @param window Pointer to the \ref Window whose \ref ClickManager we want
//! @return Pointer to a \ref ClickManager
ClickManager *window_manager_get_window_click_manager(Window *window);
