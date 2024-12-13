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

#include "os/mutex.h"

void bt_lock_init(void);

//! Function to get the shared mutex. This is used in BTPSKRNL.c to hand
//! Bluetopia this mutex to use as its BSC_LockBluetoothStack mutex.
PebbleRecursiveMutex *bt_lock_get(void);

//! Lock the shared Bluetooth recursive lock to protect Bluetooth related state.
void bt_lock(void);

//! Unlock the shared Bluetooth recursive lock.
void bt_unlock(void);

//! Asserts whether the bt_lock() is held or not.
void bt_lock_assert_held(bool is_held);

//! Returns true if the bt lock is held, else false
bool bt_lock_is_held(void);
