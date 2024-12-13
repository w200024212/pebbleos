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

#include "util/attributes.h"

#include <bluetooth/sm_types.h>
#include <bluetooth/dis.h>

#include <stdbool.h>

typedef struct PACKED BTDriverConfig {
  SM128BitKey root_keys[SMRootKeyTypeNum];
  DisInfo dis_info;
  BTDeviceAddress identity_addr;
  bool is_hrm_supported_and_enabled;
} BTDriverConfig;

//! Function that performs one-time initialization of the BT Driver.
//! The main FW is expected to call this once at boot.
void bt_driver_init(void);

//! Starts the Bluetooth stack.
//! @return True if the stack started successfully.
bool bt_driver_start(BTDriverConfig *config);

//! Stops the Bluetooth stack.
//! @return True if the stack stopped successfully.
void bt_driver_stop(void);

//! Powers down the BT controller if has yet to be used
void bt_driver_power_down_controller_on_boot(void);
