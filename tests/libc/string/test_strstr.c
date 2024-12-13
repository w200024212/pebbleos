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

#include <stdint.h>
#include <string.h>

#include "clar.h"

// "Define" libc functions we're testing
#include "pblibc_private.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//! Tests

void test_strstr__basic(void) {
  char testbuf[8] = "Hello!B";
  cl_assert_equal_p(strstr(testbuf, "lo!"), testbuf+3);
  cl_assert_equal_p(strstr(testbuf, "log"), NULL);
}

void test_strstr__weird(void) {
  char testbuf[8] = "He\0llo!B";
  cl_assert_equal_p(strstr(testbuf, "l"), NULL);
  cl_assert_equal_p(strstr(testbuf, "He"), testbuf);
}
