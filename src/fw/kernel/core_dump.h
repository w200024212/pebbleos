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
#include "util/build_id.h"
#include "system/status_codes.h"

#include <stdbool.h>

//! NOTE: This function performs a hard reset after the core dump and never returns
NORETURN core_dump_reset(bool is_forced);

bool is_unread_coredump_available(void);

// Used for unit tests
void core_dump_test_force_bus_fault(void);
void core_dump_test_force_inf_loop(void);
void core_dump_test_force_assert(void);


// Warning: these functions use the normal flash driver
status_t core_dump_size(uint32_t flash_base, uint32_t *size);
void core_dump_mark_read(uint32_t flash_base);
bool core_dump_is_unread_available(uint32_t flash_base);
uint32_t core_dump_get_slot_address(unsigned int i);

// Bluetooth Core Dump API
bool core_dump_reserve_ble_slot(uint32_t *flash_base, uint32_t *max_size,
                                ElfExternalNote *build_id);
