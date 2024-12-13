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

#include "dis.h"

#include "comm/ble/ble_log.h"
#include "comm/ble/gap_le_connection.h"
#include "comm/ble/kernel_le_client/ancs/ancs.h"
#include "comm/bt_lock.h"
#include "system/logging.h"
#include "system/passert.h"

// -------------------------------------------------------------------------------------------------
// Interface towards kernel_le_client.c

void dis_invalidate_all_references(void) {
}

void dis_handle_service_removed(BLECharacteristic *characteristics, uint8_t num_characteristics) {
  // dis_service_discovered doesn't get set to false here, since services can temporarily disappear
  // and we're just using this to detect whether or not we're on iOS 9
}

void dis_handle_service_discovered(BLECharacteristic *characteristics) {
  BLE_LOG_DEBUG("In DIS service discovery CB");
  PBL_ASSERTN(characteristics);

  ancs_handle_ios9_or_newer_detected();
}
