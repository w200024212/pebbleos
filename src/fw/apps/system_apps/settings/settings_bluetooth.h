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

#include "kernel/events.h"
#include "settings_menu.h"
#include "util/list.h"

typedef struct GAPLEConnection GAPLEConnection;

typedef enum StoredRemoteType {
  StoredRemoteTypeBTClassic,
  StoredRemoteTypeBLE,
  StoredRemoteTypeBTDual,
} StoredRemoteType;

typedef struct StoredRemoteClassic {
  bool connected;
  BTDeviceAddress bd_addr;
} StoredRemoteClassic;

typedef struct StoredRemoteBLE {
  BTBondingID bonding;
  GAPLEConnection *connection;
#if CAPABILITY_HAS_BUILTIN_HRM
  bool is_sharing_heart_rate;
#endif
} StoredRemoteBLE;

typedef struct StoredRemoteDual {
  StoredRemoteClassic classic;
  StoredRemoteBLE ble;
} StoredRemoteDual;

typedef struct StoredRemote {
  ListNode list_node;
  char name[BT_DEVICE_NAME_BUFFER_SIZE];
  StoredRemoteType type;
  union {
    StoredRemoteClassic classic;
    StoredRemoteBLE ble;
    StoredRemoteDual dual;
  };
} StoredRemote;

struct SettingsBluetoothData;

void settings_bluetooth_update_remotes(struct SettingsBluetoothData *data);

const SettingsModuleMetadata *settings_bluetooth_get_info(void);

bool settings_bluetooth_is_sharing_heart_rate_for_stored_remote(StoredRemote* remote);

#define BT_FORGET_PAIRING_STR \
  i18n_noop("Remember to also forget your Pebble's Bluetooth connection from your phone.")
