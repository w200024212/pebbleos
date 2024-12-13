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

#include <bluetooth/responsiveness.h>

typedef struct GAPLEConnection GAPLEConnection;

typedef struct GAPLEConnectRequestParams {
  uint16_t connection_interval_min_1_25ms;
  uint16_t connection_interval_max_1_25ms;
  uint16_t slave_latency_events;
  uint16_t supervision_timeout_10ms;
} GAPLEConnectRequestParams;

//! Requests a desired connection speed/power/latency behavior.
//! @param connection The connection for which the request the behavior.
//! @param desired_state The desired behavior.
//! @note The change does not take effect immediately. When Pebble is the LE slave, it depends on
//! the other side (master) to actually act upon the request and apply the change. With iOS
//! devices, this does not always happen.
void gap_le_connect_params_request(GAPLEConnection *connection,
                                   ResponseTimeState desired_state);
