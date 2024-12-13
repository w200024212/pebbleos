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

///////////////////////////////////////
// Implements:
//   char *strchr(const char *s1, int c);
//   char *strrchr(const char *s1, int c);
///////////////////////////////////////
// Notes:
//   Tuned for code size.

#include <stddef.h>
#include <string.h>
#include <pblibc_private.h>

char *strchr(const char *s, int c) {
  size_t n = strlen(s) + 1;
  return memchr(s, c, n);
}

char *strrchr(const char *s, int c) {
  char ch = (char)c;
  size_t i = strlen(s);
  do {
    if (s[i] == ch) {
      return (char*)&s[i];
    }
  } while (i--);
  return NULL;
}
