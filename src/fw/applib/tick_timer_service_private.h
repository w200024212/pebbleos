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

#include "event_service_client.h"
#include "tick_timer_service.h"

typedef struct __attribute__((packed)) TickTimerServiceState {
  TickHandler handler;
  TimeUnits tick_units;
  struct tm last_time;
  bool first_tick;

  EventServiceInfo tick_service_info;
} TickTimerServiceState;

void tick_timer_service_state_init(TickTimerServiceState *state);

//! @internal
//! initializes an event service that responds to PEBBLE_TICK_EVENT
void tick_timer_service_init(void);

//! @internal
//! de-register the tick timer handler
void tick_timer_service_reset(void);
