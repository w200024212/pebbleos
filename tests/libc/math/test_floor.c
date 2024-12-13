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
#include <limits.h>
#include <math.h>

#include "clar.h"

// "Define" libc functions we're testing
#include "pblibc_private.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//! Tests

void test_floor__basic(void) {
  cl_assert(floor( 0.5) ==  0.0);
  cl_assert(floor(-0.5) == -1.0);
  cl_assert(floor( 0.0) ==  0.0);
  cl_assert(floor(-0.0) == -0.0);
  cl_assert(floor( 1.5) ==  1.0);
  cl_assert(floor(-1.5) == -2.0);
  cl_assert(floor( 2.0) ==  2.0);
  cl_assert(floor(-2.0) == -2.0);
  cl_assert(floor( 0.0001) ==  0.0);
  cl_assert(floor(-0.0001) == -1.0);
  cl_assert(isnan(floor(NAN)));
  cl_assert(isinf(floor(INFINITY)));
}
