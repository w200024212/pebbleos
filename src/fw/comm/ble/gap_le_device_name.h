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

#include "gap_le_connection.h"

#include <bluetooth/bluetooth_types.h>

//! Requests the device name, caches the result in bt_persistent_storage and into
//! connection->device_name.
void gap_le_device_name_request(const BTDeviceInternal *address);

//! Convenience wrapper to request the device name for each connected BLE device, by calling
//! gap_le_device_name_request for each connection.
void gap_le_device_name_request_all(void);
