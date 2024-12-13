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

#include "services/common/bluetooth/bluetooth_persistent_storage.h"

void fake_bt_persistent_storage_reset(void);

BTBondingID fake_bt_persistent_storage_add(const SMIdentityResolvingKey *irk,
				    const BTDeviceInternal *device,
				    const char name[BT_DEVICE_NAME_BUFFER_SIZE],
				    bool is_gateway);
