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

#include <inttypes.h>

#include "comm/ble/gap_le_scan.h"

//! Returns true on success, false on failure
bool bt_driver_start_le_scan(bool active_scan, bool use_white_list_filter, bool filter_dups,
                         uint16_t scan_interval_ms, uint16_t scan_window_ms);

//! Returns true on success, false on failure
bool bt_driver_stop_le_scan(void);

extern void bt_driver_cb_le_scan_handle_report(const GAPLERawAdReport *data, int length);
