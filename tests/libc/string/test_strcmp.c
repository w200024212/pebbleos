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
// Asserting !strcmp as a bool:
//   True = equal
//   False = non-equal

void test_strcmp__same_buffer(void) {
  char testbuf[8] = "Hello!\0\0";
  cl_assert_equal_b(!strcmp(testbuf, testbuf), true);
}

void test_strcmp__same_content(void) {
  char testbuf1[8] = "Hello!\0\0";
  char testbuf2[8] = "Hello\0\0\0";
  testbuf2[5] = '!';
  cl_assert_equal_b(!strcmp(testbuf1, testbuf2), true);
}

void test_strcmp__different_content(void) {
  char testbuf1[8] = "Hello!\0\0";
  char testbuf2[8] = "Hello\0\0\0";
  cl_assert_equal_b(!strcmp(testbuf1, testbuf2), false);
}

void test_strcmp__n_same_buffer(void) {
  char testbuf[8] = "Hello!\0\0";
  cl_assert_equal_b(!strncmp(testbuf, testbuf, 8), true);
}

void test_strcmp__n_same_content(void) {
  char testbuf1[8] = "Hello!\0\0";
  char testbuf2[8] = "Hello\0\0\0";
  testbuf2[5] = '!';
  cl_assert_equal_b(!strncmp(testbuf1, testbuf2, 8), true);
}

void test_strcmp__n_different_content(void) {
  char testbuf1[8] = "Hello!\0\0";
  char testbuf2[8] = "Hello\0\0\0";
  cl_assert_equal_b(!strncmp(testbuf1, testbuf2, 8), false);
}

void test_strcmp__n_short(void) {
  char testbuf1[8] = "Hello!G\0";
  char testbuf2[8] = "HelloAB\0";
  cl_assert_equal_b(!strncmp(testbuf1, testbuf2, 5), true);
}
