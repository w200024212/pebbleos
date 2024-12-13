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
//   int atoi(const char *nptr);
//   long int atol(const char *nptr);
///////////////////////////////////////
// Exports to apps:
//   atoi, atol

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <pblibc_private.h>

intmax_t strtoX_core(const char * restrict nptr, char ** restrict endptr, int base, bool do_errors,
                     intmax_t max, intmax_t min);

int atoi(const char *nptr) {
  return strtoX_core(nptr, NULL, 10, false, INT_MAX, INT_MIN);
}

long int atol(const char *nptr) {
  return strtoX_core(nptr, NULL, 10, false, INT_MAX, INT_MIN);
}
