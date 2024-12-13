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

//! Reference counted request to allow us to be discovered and paired with over BT Classic & LE.
void bt_pairability_use(void);

//! Reference counted request to allow us to be discovered and paired with over BT Classic.
void bt_pairability_use_bt(void);

//! Reference counted request to allow us to be discovered and paired with over BLE.
void bt_pairability_use_ble(void);

//! Reference counted request to allow us to be discovered and paired with over BLE for a specific
//! period, after which bt_pairability_release_ble will be called automatically.
void bt_pairability_use_ble_for_period(uint16_t duration_secs);

//! Reference counted request to disallow us to be discovered and paired with over BT Classic & LE.
void bt_pairability_release(void);

//! Reference counted request to disallow us to be discovered and paired with over BT Classic.
void bt_pairability_release_bt(void);

//! Reference counted request to disallow us to be discovered and paired with over BLE.
void bt_pairability_release_ble(void);

//! Evaluates whether there are any bondings to gateways. If there are none, make the system
//! discoverable and pairable.
void bt_pairability_update_due_to_bonding_change(void);

void bt_pairability_init(void);
