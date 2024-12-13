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

#include "comm/ble/gap_le_connection.h"

//! Bluetooth LE GAP Device name APIs
void bt_driver_gap_le_device_name_request_all(void);
void bt_driver_gap_le_device_name_request(const BTDeviceInternal *address);

//! The caller is expected to have implemented:
//! ctx will be kernel_free()'d
void bt_driver_store_device_name_kernelbg_cb(void *ctx);
