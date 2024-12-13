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

typedef enum {
  AppLaunchCharacteristicAppLaunch,
  AppLaunchCharacteristicNum
} AppLaunchCharacteristic;

void app_launch_handle_service_discovered(BLECharacteristic *characteristics);

void app_launch_invalidate_all_references(void);

void app_launch_handle_service_removed(
    BLECharacteristic *characteristics, uint8_t num_characteristics);

bool app_launch_can_handle_characteristic(BLECharacteristic characteristic);

void app_launch_handle_read_or_notification(BLECharacteristic characteristic, const uint8_t *value,
                                         size_t value_length, BLEGATTError error);

void app_launch_handle_disconnection(void);

void app_launch_trigger(void);
