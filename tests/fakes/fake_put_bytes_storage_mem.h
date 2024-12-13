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

#include "services/common/put_bytes/put_bytes.h"
#include "system/firmware_storage.h"

#include <stddef.h>
#include <stdint.h>

uint32_t fake_pb_storage_mem_get_max_size(PutBytesObjectType object_type);

void fake_pb_storage_mem_reset(void);

void fake_pb_storage_mem_set_crc(uint32_t crc);

bool fake_pb_storage_mem_get_last_success(void);

void fake_pb_storage_mem_assert_contents_written(const uint8_t contents[], size_t size);

void fake_pb_storage_mem_assert_fw_description_written(const FirmwareDescription *fw_descr);

void fake_pb_storage_register_cb_before_write(void (*cb_before_write)(void));
