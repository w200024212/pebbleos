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

#include "logging.h"


void passert_failed(const char* filename, int line_number, const char* message, ...)
    __attribute__((noreturn));

#define PBL_ASSERT(expr, ...) \
  do { \
    if (!(expr)) { \
      passert_failed(__FILE_NAME__, __LINE__, __VA_ARGS__); \
    } \
  } while (0)

#define PBL_ASSERTN(expr) \
  do { \
    if (!(expr)) { \
      passert_failed_no_message(__FILE_NAME__, __LINE__); \
    } \
  } while (0)

void passert_failed_no_message(const char* filename, int line_number)
    __attribute__((noreturn));

void wtf(void) __attribute__((noreturn));

#define WTF wtf()

// Insert a compiled-in breakpoint
#define BREAKPOINT __asm("bkpt")

#define PBL_ASSERT_PRIVILEGED()
#define PBL_ASSERT_TASK(task)

#define PBL_CROAK(fmt, args...) \
    passert_failed(__FILE_NAME__, __LINE__, "*** CROAK: " fmt, ## args)
