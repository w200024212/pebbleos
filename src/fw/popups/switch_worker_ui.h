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

#include "applib/ui/window_stack.h"
#include "kernel/events.h"

//! @param new_worker_id The new ID that we'd like to ask the user to switch to
//! @param set_as_default Whether this new worker should become the default after being accepted
//! @param window_stack Which window stack to push the dialog to
//! @param exit_callback Callback to be called on dialog pop (may be NULL if not used)
//! @param callback_context Context which is passed to provided callbacks
void switch_worker_confirm(AppInstallId new_worker_id, bool set_as_default,
                           WindowStack *window_stack);

