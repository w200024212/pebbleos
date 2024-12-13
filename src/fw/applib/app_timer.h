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

#include <stdbool.h>
#include <stdint.h>

//! @addtogroup Foundation
//! @{
//!   @addtogroup Timer
//!   \brief Can be used to execute some code at some point in the future.
//!   @{

//! An opaque handle to a timer
struct AppTimer;
typedef struct AppTimer AppTimer;

//! The type of function which can be called when a timer fires.  The argument will be the @p callback_data passed to
//! @ref app_timer_register().
typedef void (*AppTimerCallback)(void* data);

//! Registers a timer that ends up in callback being called some specified time in the future.
//! @param timeout_ms The expiry time in milliseconds from the current time
//! @param callback The callback that gets called at expiry time
//! @param callback_data The data that will be passed to callback
//! @return A pointer to an `AppTimer` that can be used to later reschedule or cancel this timer
AppTimer* app_timer_register(uint32_t timeout_ms, AppTimerCallback callback, void* callback_data);

//! @internal
//! Registers a timer that ends up in callback being called repeatedly at a specified interval
//! @param timeout_ms The interval time in milliseconds from the current time
//! @param callback The callback that gets called at every interval
//! @param callback_data The data that will be passed to callback
//! @return A pointer to an `AppTimer` that can be used to later reschedule or cancel this timer
AppTimer* app_timer_register_repeatable(uint32_t timeout_ms,
                                        AppTimerCallback callback,
                                        void* callback_data,
                                        bool repeating);

//! @internal
//! Get the data passed to the app timer
void *app_timer_get_data(AppTimer *timer);

//! Reschedules an already running timer for some point in the future.
//! @param timer_handle The timer to reschedule
//! @param new_timeout_ms The new expiry time in milliseconds from the current time
//! @return true if the timer was rescheduled, false if the timer has already elapsed
bool app_timer_reschedule(AppTimer *timer_handle, uint32_t new_timeout_ms);

//! Cancels an already registered timer.
//! Once cancelled the handle may no longer be used for any purpose.
void app_timer_cancel(AppTimer *timer_handle);

//!   @} // group Timer
//! @} // group Foundation

