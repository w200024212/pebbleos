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
//   int strcmp(const char *s1, const char *s2);
//   int strncmp(const char *s1, const char *s2, size_t n);
///////////////////////////////////////
// Exports to apps:
//   strcmp, strncmp
///////////////////////////////////////
// Notes:
//   Tuned for code size.

#include <stddef.h>
#include <string.h>
#include <pblibc_private.h>

int strcmp(const char *s1, const char *s2) {
  size_t n = strlen(s1) + 1;
  return memcmp(s1, s2, n);
}

int strncmp(const char *s1, const char *s2, size_t n) {
  size_t strn = strlen(s1) + 1;
  if (strn < n) {
    n = strn;
  }
  return memcmp(s1, s2, n);
}
