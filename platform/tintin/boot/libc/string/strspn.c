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
//   size_t strcspn(const char *s1, const char *s2);
//   size_t strspn(const char *s1, const char *s2);

#include <stddef.h>
#include <string.h>

size_t strcspn(const char *s1, const char *s2) {
  size_t len = 0;
  const char *p;
  while (s1[len]) {
    p = s2;
    while (*p) {
      if (s1[len] == *p++) {
        return len;
      }
    }
    len++;
  }
  return len;
}

size_t strspn(const char *s1, const char *s2) {
  size_t len = 0;
  const char *p;
  while (s1[len]) {
    p = s2;
    while (*p) {
      if (s1[len] == *p) {
        break;
      }
      p++;
    }
    if (!*p) {
      return len;
    }
    len++;
  }
  return len;
}
