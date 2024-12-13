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

#include "util/crc8.h"

uint8_t crc8_calculate_bytes(const uint8_t *data, uint32_t data_len, bool big_endian) {
  uint8_t checksum = 0;
  crc8_calculate_bytes_streaming(data, data_len, &checksum, big_endian);
  return checksum;
}

void crc8_calculate_bytes_streaming(const uint8_t *data, uint32_t data_len, uint8_t *crc,
                                    bool big_endian) {
  // Optimal polynomial chosen based on
  // http://users.ece.cmu.edu/~koopman/roses/dsn04/koopman04_crc_poly_embedded.pdf
  // Note that this is different than the standard CRC-8 polynomial, because the
  // standard CRC-8 polynomial is not particularly good.

  // nibble lookup table for (x^8 + x^5 + x^3 + x^2 + x + 1)
  static const uint8_t lookup_table[] =
      { 0, 47, 94, 113, 188, 147, 226, 205, 87, 120, 9, 38, 235, 196,
        181, 154 };

  for (uint32_t i = 0; i < data_len * 2; i++) {
    uint8_t nibble;
    if (big_endian) {
      nibble = data[data_len - (i / 2) - 1];
    } else {
      nibble = data[i / 2];
    }
    if (i % 2 == 0) {
      nibble >>= 4;
    }
    int index = nibble ^ (*crc >> 4);
    *crc = lookup_table[index & 0xf] ^ ((*crc << 4) & 0xf0);
  }
}
