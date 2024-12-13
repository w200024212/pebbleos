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

#include "get_bytes_storage.h"

bool gb_storage_flash_setup(GetBytesStorage *storage, GetBytesObjectType object_type,
                            GetBytesStorageInfo *info);

GetBytesInfoErrorCode gb_storage_flash_get_size(GetBytesStorage *storage, uint32_t *size);

bool gb_storage_flash_read_next_chunk(GetBytesStorage *storage, uint8_t *buffer, uint32_t len);

void gb_storage_flash_cleanup(GetBytesStorage *storage, bool successful);
