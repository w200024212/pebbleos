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

#include "dis.h"

#include <btutil/bt_device.h>

//! DIS Service UUID - 0000180A-0000-1000-8000-00805F9B34FB
static const Uuid s_dis_service_uuid = {
  BT_UUID_EXPAND(0x180A)
};

//! DIS Characteristic UUIDs
static const Uuid s_dis_characteristic_uuids[NumDISCharacteristic] = {
  //! Manufacturer Name String - 00002A29-0000-1000-8000-00805F9B34FB
  [DISCharacteristicManufacturerNameString] = {
    BT_UUID_EXPAND(0x2A29)
  },
};
