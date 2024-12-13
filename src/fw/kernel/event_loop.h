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

#include "kernel/events.h"

#include <stdbool.h>

//! Adds an event to the launcher's queue that will call the callback with
//! arbitrary data as argument. Make sure that data points to memory that lives
//! past the point of calling this function.
//! @param callback Function pointer to the callback to be called
//! @param data Pointer to arbitrary data that will be passed as an argument to the callback
void launcher_task_add_callback(CallbackEventCallback callback, void *data);

bool launcher_task_is_current_task(void);

//! Increment or decrement a reference count of services that want the launcher
//! to block pop-ups; used by getting started and firmware update
void launcher_block_popups(bool ignore);

//! Returns true if popups are currently being blocked
bool launcher_popups_are_blocked(void);

void launcher_main_loop(void);

//! Cancel the force quit timer that may currently be running if the back button
//! was pressed down.
void launcher_cancel_force_quit(void);
