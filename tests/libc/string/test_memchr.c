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

void test_memchr__basic(void) {
  uint8_t testbuf[8] = { 0x12, 0x34, 0x56, 0x78, 0x12, 0x78, 0xDE, 0xF0, };
  cl_assert_equal_p(memchr(testbuf, 0x78, 8), testbuf+3);
}

void test_memchr__unfound(void) {
  uint8_t testbuf[8] = { 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, };
  cl_assert_equal_p(memchr(testbuf, 0xFF, 8), NULL);
}

void test_memchr__short_found(void) {
  uint8_t testbuf[8] = { 0x12, 0x34, 0x56, 0x78, 0x9A, 0x78, 0xDE, 0xF0, };
  cl_assert_equal_p(memchr(testbuf, 0x78, 4), testbuf+3);
}

void test_memchr__short_unfound(void) {
  uint8_t testbuf[8] = { 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, };
  cl_assert_equal_p(memchr(testbuf, 0x9A, 4), NULL);
}

void test_memchr__big_value(void) {
  uint8_t testbuf[8] = { 0x12, 0x34, 0x56, 0x78, 0x9A, 0x78, 0xDE, 0xF0, };
  cl_assert_equal_p(memchr(testbuf, 0xF78, 8), testbuf+3);
}
