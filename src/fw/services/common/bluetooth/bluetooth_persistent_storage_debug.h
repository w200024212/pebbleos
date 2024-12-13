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

#include <bluetooth/bluetooth_types.h>
#include <bluetooth/sm_types.h>
#include <btutil/sm_util.h>

#define DISPLAY_BUF_LEN 160

void bluetooth_persistent_storage_debug_dump_ble_pairing_info(
    char *display_buf, const SMPairingInfo *info);

void bluetooth_persistent_storage_debug_dump_classic_pairing_info(
    char *display_buf, BTDeviceAddress *addr, char *device_name, SM128BitKey *link_key,
    uint8_t platform_bits);

void bluetooth_persistent_storage_debug_dump_root_keys(SM128BitKey *irk, SM128BitKey *erk);
