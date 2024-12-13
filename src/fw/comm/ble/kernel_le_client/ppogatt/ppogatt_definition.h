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

#include "ppogatt.h"

#include <bluetooth/pebble_bt.h>

static const Uuid s_ppogatt_service_uuid = {
  PEBBLE_BT_UUID_EXPAND(PEBBLE_BT_PPOGATT_SERVICE_UUID_32BIT)
};

static const Uuid s_ppogatt_characteristic_uuids[PPoGATTCharacteristicNum] = {
  [PPoGATTCharacteristicData] = {
    PEBBLE_BT_UUID_EXPAND(PEBBLE_BT_PPOGATT_DATA_CHARACTERISTIC_UUID_32BIT),
  },
  [PPoGATTCharacteristicMeta] = {
    PEBBLE_BT_UUID_EXPAND(PEBBLE_BT_PPOGATT_META_CHARACTERISTIC_UUID_32BIT),
  },
};
