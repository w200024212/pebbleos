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
// Asserting !memcmp as a bool:
//   True = equal
//   False = non-equal

void test_memcmp__same_buffer(void) {
  uint8_t testbuf[8] = { 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, };
  cl_assert_equal_b(!memcmp(testbuf, testbuf, 8), true);
}

void test_memcmp__same_content(void) {
  uint8_t testbuf1[8] = { 0x12, 0x00, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, };
  uint8_t testbuf2[8] = { 0x12, 0x00, 0x56, 0x78, 0x00, 0xBC, 0xDE, 0xF0, };
  testbuf2[4] = 0x9A;
  cl_assert_equal_b(!memcmp(testbuf1, testbuf2, 8), true);
}

void test_memcmp__different_content(void) {
  uint8_t testbuf1[8] = { 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, };
  uint8_t testbuf2[8] = { 0x12, 0x34, 0x56, 0x78, 0x00, 0xBC, 0xDE, 0xF0, };
  cl_assert_equal_b(!memcmp(testbuf1, testbuf2, 8), false);
}

void test_memcmp__partial(void) {
  uint8_t testbuf1[9] = { 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, 0x0D, };
  uint8_t testbuf2[9] = { 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, 0xBA, };
  cl_assert_equal_b(!memcmp(testbuf1, testbuf2, 8), true);
}
