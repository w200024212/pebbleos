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

///////////////////////////////////////
// Implements:
//   double floor(double x);

#include <pblibc_private.h>

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

// TODO: PBL-36144 replace this naive implementation with __builtin_floor()

#ifndef NAN
#define NAN         (0.0/0.0)
#endif

#ifndef INFINITY
#define INFINITY    (1.0/0.0)
#endif

#ifndef isinf
#define isinf(y) (__builtin_isinf(y))
#endif

#ifndef isnan
#define isnan(y) (__builtin_isnan(y))
#endif


double floor(double x) {
  if (isnan(x)) {
    return NAN;
  }
  if (isinf(x)) {
    return INFINITY;
  }

  const int64_t x_int = (int64_t)x;
  const bool has_no_fraction = (double)x_int == x;
  return (double)((x >= 0 || has_no_fraction) ? x_int : x_int - 1);
}
