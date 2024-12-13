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

//! Different states supported by the status LED.
typedef enum {
  StatusLedState_Off,
  StatusLedState_Charging,
  StatusLedState_FullyCharged,

  StatusLedStateCount
} StatusLedState;

//! Set the status LED to a new state. Note that this function is a no-op on boards that don't
//! have a status LED.
void status_led_set(StatusLedState state);
