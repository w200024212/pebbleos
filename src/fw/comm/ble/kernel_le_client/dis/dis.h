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

#include "applib/bluetooth/ble_client.h"

//! @file dis.h Module implementing an DIS client.
//! See https://developer.bluetooth.org/TechnologyOverview/Pages/DIS.aspx

//! Enum indexing the DIS characteristics
typedef enum {
  // We need at least one characteristic to look up the GAPLEConnection & flag the presence of DIS
  // since Apple doesn't expose the SW version yet
  DISCharacteristicManufacturerNameString = 0,
  NumDISCharacteristic,

  DISCharacteristicInvalid = NumDISCharacteristic,
} DISCharacteristic;

//! Updates the /ref GAPLEConnection to register that the DIS service has been discovered
//! @param characteristics Matrix of characteristics references of the DIS service
void dis_handle_service_discovered(BLECharacteristic *characteristics);

void dis_invalidate_all_references(void);

void dis_handle_service_removed(BLECharacteristic *characteristics, uint8_t num_characteristics);
