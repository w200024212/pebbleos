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

#include "pulse_bulkio_domain_handler.h"

#include "system/status_codes.h"
#include "util/attributes.h"

#include <stdint.h>
#include <string.h>

typedef struct PACKED MemoryEraseOptions {
  uint32_t address;
  uint32_t length;
} MemoryEraseOptions;

static int memory_domain_read(uint8_t *buf, uint32_t address, uint32_t length,
                                    void *context) {
  memcpy(buf, (void *)address, length);
  return length;
}

static int memory_domain_write(uint8_t *buf, uint32_t address, uint32_t length,
                                    void *context) {
  memcpy(buf, (void *)address, length);
  return length;
}

static int memory_domain_stat(uint8_t *resp, size_t resp_max_len, void *context) {
  return E_INVALID_OPERATION;
}

static status_t memory_domain_erase(uint8_t *packet_data, size_t length, uint8_t cookie) {
  if (length != sizeof(MemoryEraseOptions)) {
    return E_INVALID_ARGUMENT;
  }

  MemoryEraseOptions *options = (MemoryEraseOptions*)packet_data;

  memset((void *)options->address, 0x0, length);
  return S_SUCCESS;
}

static status_t memory_domain_open(uint8_t *packet_data, size_t length, void **resp) {
  return S_SUCCESS;
}

static status_t memory_domain_close(void *context) {
  return S_SUCCESS;
}

PulseBulkIODomainHandler pulse_bulkio_domain_memory = {
  .id = PulseBulkIODomainType_Memory,
  .open_proc = memory_domain_open,
  .close_proc = memory_domain_close,
  .read_proc = memory_domain_read,
  .write_proc = memory_domain_write,
  .stat_proc = memory_domain_stat,
  .erase_proc = memory_domain_erase
};
