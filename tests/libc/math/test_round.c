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

#include <math.h>

#include "clar.h"

// "Define" libc functions we're testing
#include "pblibc_private.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//! Tests

void test_round__round(void) {
  cl_assert_equal_d(round(0.0), 0.0);
  cl_assert_equal_d(round(0.4), 0.0);
  cl_assert_equal_d(round(-0.4), -0.0);
  cl_assert_equal_d(round(0.5), 1.0);
  cl_assert_equal_d(round(-0.5), -1.0);
  cl_assert_equal_d(round(-1.0), -1.0);
  cl_assert_equal_d(round(1.7976931348623157e+308), 1.7976931348623157e+308);
  cl_assert_equal_d(round(2.2250738585072014e-308), -0.0);
}
