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

#include "bt_device.h"
#include <bluetooth/bluetooth_types.h>

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

BTDevice bt_device_init_with_address(BTDeviceAddress address, bool is_random) {
  BTDeviceInternal device = {
    .address = address,
    .is_classic = false,
    .is_random_address = is_random,
  };
  return device.opaque;
}

BTDeviceAddress bt_device_get_address(BTDevice device) {
  return ((BTDeviceInternal *) &device)->address;
}

bool bt_device_address_equal(const BTDeviceAddress *addr1,
                             const BTDeviceAddress *addr2) {
  if (addr1 == NULL || addr2 == NULL) {
    return false;
  }
  return memcmp(addr1, addr2, sizeof(BTDeviceAddress)) == 0;
}

bool bt_device_address_is_invalid(const BTDeviceAddress *addr) {
  if (!addr) {
    return true;
  }
  BTDeviceAddress invalid = {};
  return bt_device_address_equal(addr, &invalid);
}

bool bt_device_internal_equal(const BTDeviceInternal *device1_int,
                              const BTDeviceInternal *device2_int) {
  if (device1_int == NULL || device2_int == NULL) {
    return false;
  }
  return (device1_int->is_classic == device2_int->is_classic &&
          device1_int->is_random_address == device2_int->is_random_address &&
          bt_device_address_equal(&device1_int->address, &device2_int->address));
}

bool bt_device_equal(const BTDevice *device1, const BTDevice *device2) {
  const BTDeviceInternal *device1_int = (const BTDeviceInternal *) device1;
  const BTDeviceInternal *device2_int = (const BTDeviceInternal *) device2;
  return bt_device_internal_equal(device1_int, device2_int);
}

bool bt_device_is_invalid(const BTDevice *device) {
  const BTDevice invalid_device = BT_DEVICE_INVALID;
  return bt_device_equal(device, &invalid_device);
}
