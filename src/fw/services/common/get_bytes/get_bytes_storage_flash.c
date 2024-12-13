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

#include "get_bytes_storage.h"
#include "drivers/flash.h"
#include "kernel/pbl_malloc.h"
#include "flash_region/flash_region.h"


bool gb_storage_flash_setup(
    GetBytesStorage *storage, GetBytesObjectType object_type, GetBytesStorageInfo *info) {
  if (!info->flash_len || (info->flash_start_addr + info->flash_len) > BOARD_NOR_FLASH_SIZE) {
    return false;
  }
  storage->impl_data = kernel_zalloc_check(sizeof(*info));
  memcpy(storage->impl_data, info, sizeof(*info));

  return true;
}

GetBytesInfoErrorCode gb_storage_flash_get_size(GetBytesStorage *storage, uint32_t *size) {
  *size = ((GetBytesStorageInfo *)storage->impl_data)->flash_len;
  return GET_BYTES_OK;
}

bool gb_storage_flash_read_next_chunk(GetBytesStorage *storage, uint8_t *buffer, uint32_t len) {
  uint32_t start_offset =  ((GetBytesStorageInfo *)storage->impl_data)->flash_start_addr;
  flash_read_bytes(buffer, storage->current_offset + start_offset, len);
  storage->current_offset += len;
  return true;
}

void gb_storage_flash_cleanup(GetBytesStorage *storage, bool successful) {
  kernel_free(storage->impl_data);
}
