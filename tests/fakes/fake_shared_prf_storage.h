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

void fake_shared_prf_storage_reset_counts(void);
int fake_shared_prf_storage_get_ble_store_count(void);
int fake_shared_prf_storage_get_ble_delete_count(void);
int fake_shared_prf_storage_get_bt_classic_store_count(void);
int fake_shared_prf_storage_get_bt_classic_platform_bits_count(void);
int fake_shared_prf_storage_get_bt_classic_delete_count(void);
