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

void test_strchr__basic(void) {
  char testbuf[8] = "Hello!B";
  cl_assert_equal_p(strchr(testbuf, 'l'), testbuf+2);
}

void test_strchr__unfound(void) {
  char testbuf[10] = "Hello!B\0Z";
  cl_assert_equal_p(strchr(testbuf, 'Z'), NULL);
}

void test_strchr__big_value(void) {
  char testbuf[8] = "Hello!B";
  cl_assert_equal_p(strchr(testbuf, 0xF00 + 'l'), testbuf+2);
}

void test_strchr__end_of_string(void) {
  char testbuf[8] = "Hello!B";
  cl_assert_equal_p(strchr(testbuf, '\0'), testbuf+7);
}

void test_strchr__r_basic(void) {
  char testbuf[8] = "Hello!B";
  cl_assert_equal_p(strrchr(testbuf, 'B'), testbuf+6);
}

void test_strchr__r_unfound(void) {
  char testbuf[10] = "Hello!B\0Z";
  cl_assert_equal_p(strrchr(testbuf, 'Z'), NULL);
}

void test_strchr__r_big_value(void) {
  char testbuf[8] = "Hello!B";
  cl_assert_equal_p(strrchr(testbuf, 0xF00 + 'B'), testbuf+6);
}

void test_strchr__r_end_of_string(void) {
  char testbuf[8] = "Hello!B";
  cl_assert_equal_p(strrchr(testbuf, '\0'), testbuf+7);
}

