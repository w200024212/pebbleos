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

#include <stdarg.h>
#include <stdio.h>
#include <setjmp.h>
#include <stdbool.h>

void passert_failed(const char* filename, int line_number, const char* message, ...) {
  if (clar_expecting_passert) {
    clar_passert_occurred = true;
    longjmp(clar_passert_jmp_buf, 1);
  } else {
    va_list ap;
    va_start(ap, message);
    printf("*** ASSERTION FAILED: %s:%u\n", filename, line_number);
    if (message) {
      vprintf(message, ap);
    }
    va_end(ap);
    printf("\n");

    // I'm lazy, don't bother formatting the message.
    cl_fail(message);
  }
  while(1);
}

void passert_failed_no_message(const char* filename, int line_number) {
  passert_failed(filename, line_number, NULL);
}

void passert_failed_no_message_with_lr(const char* filename, int line_number, uint32_t lr) {
  passert_failed(filename, line_number, NULL);
}

void croak(const char *filename, int line_number, const char *fmt, ...) {
  cl_fail(fmt);
  while(1);
}

typedef struct Heap Heap;

void croak_oom(size_t bytes, int saved_lr, Heap *heap_ptr) {
  cl_fail("CROAK OOM");
  while(1);
}

void wtf(void) {
  cl_fail("WTF");
  while(1);
}
