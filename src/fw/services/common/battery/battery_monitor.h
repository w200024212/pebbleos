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
#include "services/common/battery/battery_state.h"
#include "services/common/new_timer/new_timer.h"
#include <stdbool.h>

// The battery monitor handles power state and associated service control, in response to battery
// state changes. This includes low power and critical modes.

void battery_monitor_init(void);
void battery_monitor_handle_state_change_event(PreciseBatteryChargeState state);

// Use the battery state to determine if UI elements should be locked out
// because the battery is too low
bool battery_monitor_critical_lockout(void);

// For unit tests
TimerID battery_monitor_get_standby_timer_id(void);
