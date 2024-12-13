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

#include <stdio.h>
#include <stdarg.h>

void dbgserial_putstr(const char* str) {
  printf("%s\n", str);
}

FORMAT_PRINTF(3, 4)
void dbgserial_putstr_fmt(char* str, unsigned int size, const char *fmt, ...) {
  va_list fmt_args;
  va_start(fmt_args, fmt);
  vprintf(fmt, fmt_args);
  va_end(fmt_args);
  printf("\n");
}

void dbgserial_putchar(uint8_t character) {
  printf("%c", character);
}

void dbgserial_putchar_lazy(uint8_t c) {
  dbgserial_putchar(c);
}
