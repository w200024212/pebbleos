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

#include "drivers/flash.h"

#include "kernel/pbl_malloc.h"
#include "system/logging.h"
#include "util/crc32.h"
#include "util/legacy_checksum.h"

#include <stdint.h>

static size_t prv_allocate_crc_buffer(void **buffer) {
  // Try to allocate a big buffer for reading flash data. If we can't,
  // use a smaller one.
  unsigned int chunk_size = 1024;
  *buffer = kernel_malloc(chunk_size);
  if (!*buffer) {
    PBL_LOG(LOG_LEVEL_WARNING, "Insufficient memory for a large CRC buffer, going slow");

    chunk_size = 128;
    *buffer = kernel_malloc_check(chunk_size);
  }
  return chunk_size;
}

uint32_t flash_crc32(uint32_t flash_addr, uint32_t num_bytes) {
  void *buffer;
  unsigned int chunk_size = prv_allocate_crc_buffer(&buffer);

  uint32_t crc = CRC32_INIT;
  while (num_bytes > chunk_size) {
    flash_read_bytes(buffer, flash_addr, chunk_size);
    crc = crc32(crc, buffer, chunk_size);

    num_bytes -= chunk_size;
    flash_addr += chunk_size;
  }

  flash_read_bytes(buffer, flash_addr, num_bytes);
  crc = crc32(crc, buffer, num_bytes);

  kernel_free(buffer);

  return crc;
}

uint32_t flash_calculate_legacy_defective_checksum(uint32_t flash_addr,
                                                   uint32_t num_bytes) {
  void *buffer;
  unsigned int chunk_size = prv_allocate_crc_buffer(&buffer);

  LegacyChecksum checksum;
  legacy_defective_checksum_init(&checksum);

  while (num_bytes > chunk_size) {
    flash_read_bytes(buffer, flash_addr, chunk_size);
    legacy_defective_checksum_update(&checksum, buffer, chunk_size);

    num_bytes -= chunk_size;
    flash_addr += chunk_size;
  }

  flash_read_bytes(buffer, flash_addr, num_bytes);
  legacy_defective_checksum_update(&checksum, buffer, num_bytes);

  kernel_free(buffer);

  return legacy_defective_checksum_finish(&checksum);
}
