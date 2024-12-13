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

#include "kernel/events.h"
#include "services/common/bluetooth/bluetooth_persistent_storage.h"

//! @file kernel_le_client.h
//! Module that is responsible of connecting to the BLE gateway (aka "the phone") in order to:
//! - bootstrap the Pebble Protocol over GATT (PPoGATT) module
//! - bootstrap the ANCS module
//! - bootstrap the "Service Changed" module

void kernel_le_client_handle_bonding_change(BTBondingID bonding, BtPersistBondingOp op);

void kernel_le_client_handle_event(const PebbleEvent *event);

void kernel_le_client_init(void);

void kernel_le_client_deinit(void);
