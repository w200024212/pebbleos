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

#include "util/attributes.h"

#include <bluetooth/bluetooth_types.h>
#include <bluetooth/conn_event_stats.h>

#define NUM_LE_CHANNELS 37

typedef struct PACKED LEChannelMap {
  uint8_t byte0;
  uint8_t byte1;
  uint8_t byte2;
  uint8_t byte3;
  uint8_t byte4;
} LEChannelMap;

bool bt_driver_analytics_get_connection_quality(const BTDeviceInternal *address,
                                                uint8_t *link_quality_out, int8_t *rssi_out);

bool bt_driver_analytics_collect_ble_parameters(const BTDeviceInternal *addr,
                                                LEChannelMap *le_chan_map_res);

void bt_driver_analytics_external_collect_chip_specific_parameters(void);

void bt_driver_analytics_external_collect_bt_chip_heartbeat(void);

//! Returns true iff there are connection event stats to report
bool bt_driver_analytics_get_conn_event_stats(SlaveConnEventStats *stats);
