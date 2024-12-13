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

#include <stddef.h>
#include <string.h>

#include "util/attributes.h"

// Newer than 4.7
#if (__GNUC__ == 4 && __GNUC_MINOR__ > 7) || (__GNUC__ >= 5) || __clang__
void __aeabi_memcpy(void *dest, const void *src, size_t n) {
  memcpy(dest, src, n);
}

void __aeabi_memmove(void * restrict s1, const void * restrict s2, size_t n) {
  memmove(s1, s2, n);
}

ALIAS("__aeabi_memcpy") void __aeabi_memcpy4(void *dest, const void *src, size_t n);
ALIAS("__aeabi_memcpy") void __aeabi_memcpy8(void *dest, const void *src, size_t n);

void __aeabi_memset(void *s, size_t n, int c) {
  memset(s, c, n);
}

void __aeabi_memclr(void *addr, size_t n) {
  memset(addr, 0, n);
}

ALIAS("__aeabi_memclr") void __aeabi_memclr4(void *s, size_t n);
ALIAS("__aeabi_memclr") void __aeabi_memclr8(void *s, size_t n);

#endif
