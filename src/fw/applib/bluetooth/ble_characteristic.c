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

#include "ble_characteristic.h"

#include "syscall/syscall.h"

bool ble_characteristic_is_readable(BLECharacteristic characteristic) {
  return (sys_ble_characteristic_get_properties(characteristic) &
          BLEAttributePropertyRead);
}

bool ble_characteristic_is_writable(BLECharacteristic characteristic) {
  return (sys_ble_characteristic_get_properties(characteristic) &
          BLEAttributePropertyWrite);
}

bool ble_characteristic_is_writable_without_response(BLECharacteristic characteristic) {
  return (sys_ble_characteristic_get_properties(characteristic) &
          BLEAttributePropertyWriteWithoutResponse);
}

bool ble_characteristic_is_subscribable(BLECharacteristic characteristic) {
  return (sys_ble_characteristic_get_properties(characteristic) &
          (BLEAttributePropertyNotify | BLEAttributePropertyIndicate));
}

bool ble_characteristic_is_notifiable(BLECharacteristic characteristic) {
  return (sys_ble_characteristic_get_properties(characteristic) &
          BLEAttributePropertyNotify);
}

bool ble_characteristic_is_indicatable(BLECharacteristic characteristic) {
  return (sys_ble_characteristic_get_properties(characteristic) &
          BLEAttributePropertyIndicate);
}
