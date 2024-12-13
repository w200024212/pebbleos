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
//   void *memset(void *s, int c, size_t n);
///////////////////////////////////////
// Exports to apps:
//   memset

#include <stddef.h>
#include <pblibc_assembly.h>
#include <pblibc_private.h>

#if !MEMSET_IMPLEMENTED_IN_ASSEMBLY
void *memset(void *s, int c, size_t n) {
  unsigned char *p = (unsigned char*)s;
  while (n--) {
    *p++ = (unsigned char)c;
  }
  return s;
}
#endif
