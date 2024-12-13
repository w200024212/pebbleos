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

void test_atoi__basic(void) {
  cl_assert_equal_i(atoi("500"), 500);
  cl_assert_equal_i(atoi("765"), 765);
  cl_assert_equal_i(atoi("573888"), 573888);
  cl_assert_equal_i(atoi("713713"), 713713);
}

void test_atoi__whitespace_pfx(void) {
  cl_assert_equal_i(atoi("     500"), 500);
  cl_assert_equal_i(atoi(" 765"), 765);
  cl_assert_equal_i(atoi("                 573888"), 573888);
  cl_assert_equal_i(atoi("        713713"), 713713);
}

void test_atoi__suffix(void) {
  cl_assert_equal_i(atoi("500hurf"), 500);
  cl_assert_equal_i(atoi("765berserker"), 765);
  cl_assert_equal_i(atoi("573888 redmage"), 573888);
  cl_assert_equal_i(atoi("713713 4 job fiesta111"), 713713);
}

void test_atoi__sign(void) {
  cl_assert_equal_i(atoi("+500"), 500);
  cl_assert_equal_i(atoi("-765"), -765);
  cl_assert_equal_i(atoi("   -573888"), -573888);
  cl_assert_equal_i(atoi("  +713713"), +713713);
}

void test_atoi__error(void) {
  cl_assert_equal_i(atoi("2147483647"), 2147483647); // last valid value
  cl_assert_equal_i(atoi("4294967287"), (int)4294967287); // signed integer overflow
  // ((2147483648 * 10) + 1) & 0xFFFFFFFF
  cl_assert_equal_i(atoi("21474836481"), 1);
  // ((2147483647 * 10) + 1) & 0xFFFFFFFF
  cl_assert_equal_i(atoi("21474836471"), (int)4294967287);
  // -1 * (((2147483647 * 10) + 1) & 0xFFFFFFFF)
  cl_assert_equal_i(atoi("-21474836471"), -(int)4294967287);
}

// atol will actually behave _exactly_ the same as atoi, so these tests are just copy-pasted
// Would probably be good to make these more DRY
void test_atol__basic(void) {
  cl_assert_equal_i(atol("500"), 500);
  cl_assert_equal_i(atol("765"), 765);
  cl_assert_equal_i(atol("573888"), 573888);
  cl_assert_equal_i(atol("713713"), 713713);
}

void test_atol__whitespace_pfx(void) {
  cl_assert_equal_i(atol("     500"), 500);
  cl_assert_equal_i(atol(" 765"), 765);
  cl_assert_equal_i(atol("                 573888"), 573888);
  cl_assert_equal_i(atol("        713713"), 713713);
}

void test_atol__suffix(void) {
  cl_assert_equal_i(atol("500hurf"), 500);
  cl_assert_equal_i(atol("765berserker"), 765);
  cl_assert_equal_i(atol("573888 redmage"), 573888);
  cl_assert_equal_i(atol("713713 4 job fiesta111"), 713713);
}

void test_atol__sign(void) {
  cl_assert_equal_i(atol("+500"), 500);
  cl_assert_equal_i(atol("-765"), -765);
  cl_assert_equal_i(atol("   -573888"), -573888);
  cl_assert_equal_i(atol("  +713713"), +713713);
}

void test_atol__error(void) {
  cl_assert_equal_i(atol("2147483647"), 2147483647); // last valid value
  cl_assert_equal_i(atol("4294967287"), (int)4294967287); // signed integer overflow
  // ((2147483648 * 10) + 1) & 0xFFFFFFFF
  cl_assert_equal_i(atol("21474836481"), 1);
  // ((2147483647 * 10) + 1) & 0xFFFFFFFF
  cl_assert_equal_i(atol("21474836471"), (int)4294967287);
  // -1 * (((2147483647 * 10) + 1) & 0xFFFFFFFF)
  cl_assert_equal_i(atol("-21474836471"), -(int)4294967287);
}
