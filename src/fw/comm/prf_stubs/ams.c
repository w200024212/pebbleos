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

#include "comm/ble/kernel_le_client/ams/ams.h"

void ams_create(void) {
}

void ams_handle_service_discovered(BLECharacteristic *characteristics) {
}

bool ams_can_handle_characteristic(BLECharacteristic characteristic) {
  return false;
}

void ams_handle_subscribe(BLECharacteristic subscribed_characteristic,
                          BLESubscription subscription_type, BLEGATTError error) {
}

void ams_handle_write_response(BLECharacteristic characteristic, BLEGATTError error) {
}

void ams_handle_read_or_notification(BLECharacteristic characteristic, const uint8_t *value,
                                     size_t value_length, BLEGATTError error) {
}

void ams_invalidate_all_references(void) {
}

void ams_handle_service_removed(BLECharacteristic *characteristics, uint8_t num_characteristics) {
}

void ams_destroy(void) {
}

void ams_send_command(AMSRemoteCommandID command_id) {
}
