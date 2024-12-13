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

#include "bitset.h"

#include <stdint.h>

uint8_t count_bits_set(uint8_t *bitset_bytes, int num_bits) {
  uint8_t num_bits_set = 0;
  int num_bytes = (num_bits + 7) / 8;
  if ((num_bits % 8) != 0) {
    bitset_bytes[num_bytes] &= ((0x1 << (num_bits)) - 1);
  }

  for (int i = 0; i < num_bytes; i++) {
    num_bits_set += __builtin_popcount(bitset_bytes[i]);
  }

  return (num_bits_set);
}
