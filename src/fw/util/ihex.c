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

#include "util/ihex.h"

typedef struct IHEXRecord {
  char start;
  char data_count[2];
  char address[4];
  char type[2];
  char data[];  // Variable data and checksum
} IHEXRecord;

static void prv_hexlify(char *str, uint32_t value, uint8_t num_bytes) {
  for (int i = num_bytes * 2 - 1; i >= 0; --i) {
    uint8_t nibble = (value >> (4 * i)) & 0xF;
    if (nibble >= 0xA) {
      *str++ = 'A' + (nibble - 0xA);
    } else {
      *str++ = '0' + nibble;
    }
  }
}

void ihex_encode(uint8_t *out, uint8_t type, uint16_t address,
                 const void *data, uint8_t data_len) {
  IHEXRecord *record = (IHEXRecord *)out;
  uint8_t checksum = data_len + (address >> 8) + (address & 0xff) + type;
  record->start = ':';
  prv_hexlify(record->data_count, data_len, sizeof(data_len));
  prv_hexlify(record->address, address, sizeof(address));
  prv_hexlify(record->type, type, sizeof(type));
  for (uint16_t i = 0; i < data_len; ++i) {
    uint8_t data_byte = ((uint8_t *)data)[i];
    checksum += data_byte;
    prv_hexlify(&record->data[i*2], data_byte, sizeof(data_byte));
  }
  prv_hexlify(&record->data[data_len*2], ~checksum + 1, sizeof(checksum));
}
