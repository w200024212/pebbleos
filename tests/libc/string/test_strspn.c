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

void test_strspn__basic(void) {
  char testbuf[8] = "Hello!B";
  cl_assert_equal_i(strspn(testbuf, "Hel"), 4);
  cl_assert_equal_i(strspn(testbuf, "Heo"), 2);
  cl_assert_equal_i(strspn(testbuf, "B"), 0);
  cl_assert_equal_i(strspn(testbuf, "Helo!B"), 7);
}

void test_strspn__c_basic(void) {
  char testbuf[8] = "Hello!B";
  cl_assert_equal_i(strcspn(testbuf, "o!B"), 4);
  cl_assert_equal_i(strcspn(testbuf, "o"), 4);
  cl_assert_equal_i(strcspn(testbuf, "!"), 5);
  cl_assert_equal_i(strcspn(testbuf, "H"), 0);
}
