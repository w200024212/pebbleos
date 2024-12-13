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

void test_strcpy__basic(void) {
  char testbuf[8] = "Hello!";
  char destbuf[8] = "AAAAAAAA";
  char expectbuf[8] = "Hello!\0A";
  strcpy(destbuf, testbuf);
  cl_assert_equal_m(expectbuf, destbuf, 8);
}

void test_strcpy__weird(void) {
  char testbuf[8] = "He\0llo!";
  char destbuf[8] = "AAAAAAAA";
  char expectbuf[8] = "He\0AAAAA";
  strcpy(destbuf, testbuf);
  cl_assert_equal_m(expectbuf, destbuf, 8);
}

void test_strcpy__return(void) {
  char testbuf[8] = "Hello!";
  char destbuf[8] = "AAAAAAAA";
  cl_assert_equal_p(strcpy(destbuf, testbuf), destbuf);
}

void test_strcpy__n_basic(void) {
  char testbuf[8] = "Hello!";
  char destbuf[8] = "AAAAAAAA";
  char expectbuf[8] = "Hello!\0\0";
  strncpy(destbuf, testbuf, 8);
  cl_assert_equal_m(expectbuf, destbuf, 8);
}

void test_strcpy__n_weird(void) {
  char testbuf[8] = "He\0llo!";
  char destbuf[8] = "AAAAAAAA";
  char expectbuf[8] = "He\0\0\0\0\0\0";
  strncpy(destbuf, testbuf, 8);
  cl_assert_equal_m(expectbuf, destbuf, 8);
}

void test_strcpy__n_big_string(void) {
  char testbuf[16] = "Hello, I'm huge";
  char destbuf[8] = "AAAAAAAA";
  char expectbuf[8] = "Hello, I";
  strncpy(destbuf, testbuf, 8);
  cl_assert_equal_m(expectbuf, destbuf, 8);
}

void test_strcpy__n_return(void) {
  char testbuf[8] = "Hello!";
  char destbuf[8] = "AAAAAAAA";
  cl_assert_equal_p(strncpy(destbuf, testbuf, 8), destbuf);
}

