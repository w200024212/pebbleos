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

void test_strcat__basic(void) {
  char destbuf[9] = "hi";
  char expectbuf[9] = "hilarity";
  strcat(destbuf, "larity");
  cl_assert_equal_m(expectbuf, destbuf, 9);
}

void test_strcat__weird(void) {
  char destbuf[9] = "hi\0five";
  char expectbuf[9] = "hilarity";
  strcat(destbuf, "larity");
  cl_assert_equal_m(expectbuf, destbuf, 9);
}

void test_strcat__return(void) {
  char destbuf[9] = "hi";
  char expectbuf[9] = "hilarity";
  cl_assert_equal_p(strcat(destbuf, "larity"), destbuf);
}

void test_strcat__n_basic(void) {
  char destbuf[9] = "hi";
  char expectbuf[9] = "hilarity";
  strncat(destbuf, "larity", 6);
  cl_assert_equal_m(expectbuf, destbuf, 9);
}

void test_strcat__n_overlarge(void) {
  char destbuf[9] = "hi";
  char expectbuf[9] = "hilariou";
  strncat(destbuf, "lariousness", 6);
  cl_assert_equal_m(expectbuf, destbuf, 9);
}

void test_strcat__n_weird(void) {
  char destbuf[9] = "hi\0five";
  char expectbuf[9] = "hilariou";
  strncat(destbuf, "lariousness", 6);
  cl_assert_equal_m(expectbuf, destbuf, 9);
}

void test_strcat__n_return(void) {
  char destbuf[9] = "hi";
  char expectbuf[9] = "hilarity";
  cl_assert_equal_p(strncat(destbuf, "larity", 6), destbuf);
}
