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

#include "comm/ble/gap_le_advert.h"

//! @note The client should hold the `bt_lock` when calling these functions.
//! Also note that these functions are a workaround and should ideally not be used.
//! They are kept around to assist with a bug in the TI Bluetooth chips.

extern GAPLEAdvertisingJobRef gap_le_advert_get_current_job(void);

extern GAPLEAdvertisingJobRef gap_le_advert_get_jobs(void);

extern GAPLEAdvertisingJobTag gap_le_advert_get_job_tag(GAPLEAdvertisingJobRef job);
