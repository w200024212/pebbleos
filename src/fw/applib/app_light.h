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

//! @file light.h
//! @addtogroup UI
//! @{
//!   @addtogroup Light Light
//! \brief Controlling Pebble's backlight
//!
//! The Light API provides you with functions to turn on Pebble’s backlight or
//! put it back into automatic control. You can trigger the backlight and schedule a timer
//! to automatically disable the backlight after a short delay, which is the preferred
//! method of interacting with the backlight.
//!   @{

//! Trigger the backlight and schedule a timer to automatically disable the backlight
//! after a short delay. This is the preferred method of interacting with the backlight.
void app_light_enable_interaction(void);

//! Turn the watch's backlight on or put it back into automatic control.
//! Developers should take care when calling this function, keeping Pebble's backlight on for long periods of time
//! will rapidly deplete the battery.
//! @param enable Turn the backlight on if `true`, otherwise `false` to put it back into automatic control.
void app_light_enable(bool enable);

//!   @} // group Light
//! @} // group UI
