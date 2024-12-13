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

#include "services/common/bluetooth/bluetooth_persistent_storage.h"

typedef struct BTDeviceAddress BTDeviceAddress;

//! Pauses cycling of local Private Resolvable Address (ref counted).
//! As long as the cycling is paused, the address that is used "on air" will be stable for the
//! duration that the BT stack is up (so the address can be expected to have changed after rebooting
//! or resetting the stack).
//! In case the local address is currently pinned, this function will be a no-op.
void bt_local_addr_pause_cycling(void);

//! Resumes cycling of local Private Resolvable Address (ref counted).
//! In case the local address is currently pinned, this function will be a no-op.
void bt_local_addr_resume_cycling(void);

//! Called by BT driver to indicate what the local address was that was used during the pairing
//! and pinning was requested. See comment in the implementation for more details.
void bt_local_addr_pin(const BTDeviceAddress *addr);

//! Handler for bonding changes (deletions primarily).
void bt_local_addr_handle_bonding_change(BTBondingID bonding, BtPersistBondingOp op);

//! Called during the BT stack initialization.
void bt_local_addr_init(void);
