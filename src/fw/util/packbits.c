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

#include "packbits.h"

#include <string.h>

void packbits_unpack(const char* src, int src_length, uint8_t* dest) {
  int length = 0;
  while (length < src_length) {
    int8_t header = *((int8_t*) src++);
    length++;

    if (header >= 0) {
      int count = header + 1;
      memcpy(dest, src, count);

      dest += count;
      src += count;
      length += count;
    } else {
      int count = 1 - header;
      memset(dest, *src, count);

      dest += count;
      src += 1;
      length += 1;
    }
  }
}
