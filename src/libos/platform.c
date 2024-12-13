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

#include "os/malloc.h"
#include "os/assert.h"
#include "util/attributes.h"

#include <stdio.h>
#include <stdlib.h>

// Below are some default implementations for system-specific functions required by libos.
// These functions assume a working C standard library is linked into the program.
// For programs where this isn't the case (e.g. the Pebble FW),
// alternate implementations need to be provided.
// The functions are defined as WEAK so they may be easily overridden.

WEAK void os_log(const char *filename, int line, const char *string) {
  printf("%s:%d %s\n", filename, line, string);
}

WEAK NORETURN os_assertion_failed(const char *filename, int line) {
  os_log(filename, line, "*** OS ASSERT FAILED");
  exit(EXIT_FAILURE);
}

WEAK NORETURN os_assertion_failed_lr(const char *filename, int line, uint32_t lr) {
  os_assertion_failed(filename, line);
}

WEAK void *os_malloc(size_t size) {
  return malloc(size);
}

WEAK void *os_malloc_check(size_t size) {
  void *ptr = malloc(size);
  OS_ASSERT(ptr);
  return ptr;
}

WEAK void os_free(void *ptr) {
  free(ptr);
}
