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

#include "misc.h"

#include "drivers/dbgserial.h"

#include <stdint.h>

void itoa(uint32_t num, char *buffer, int buffer_length) {
  if (buffer_length < 11) {
    dbgserial_putstr("itoa buffer too small");
    return;
  }
  *buffer++ = '0';
  *buffer++ = 'x';

  for (int i = 7; i >= 0; --i) {
    uint32_t digit = (num & (0xf << (i * 4))) >> (i * 4);

    char c;
    if (digit < 0xa) {
      c = '0' + digit;
    } else if (digit < 0x10) {
      c = 'a' + (digit - 0xa);
    } else {
      c = ' ';
    }

    *buffer++ = c;
  }
  *buffer = '\0';
}
