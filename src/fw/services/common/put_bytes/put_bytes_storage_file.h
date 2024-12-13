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

#include "put_bytes_storage.h"

bool pb_storage_file_init(PutBytesStorage *storage, PutBytesObjectType object_type,
                          uint32_t total_size, PutBytesStorageInfo *info, uint32_t append_offset);

uint32_t pb_storage_file_get_max_size(PutBytesObjectType object_type);

void pb_storage_file_write(PutBytesStorage *storage, uint32_t offset, const uint8_t *buffer,
                           uint32_t length);

uint32_t pb_storage_file_calculate_crc(PutBytesStorage *storage, PutBytesCrcType crc_type);

void pb_storage_file_deinit(PutBytesStorage *storage, bool is_success);
