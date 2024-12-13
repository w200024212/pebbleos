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

#include "util/attributes.h"

#include <stdint.h>


// Override libgcc's table-driven __builtin_popcount implementation
#ifdef __arm__
EXTERNALLY_VISIBLE int __popcountsi2(uint32_t val) {
  // Adapted from http://www.sciencezero.org/index.php?title=ARM%3a_Count_ones_%28bit_count%29
  uint32_t tmp;
  __asm("and  %[tmp], %[val], #0xaaaaaaaa\n\t"
        "sub  %[val], %[val], %[tmp], lsr #1\n\t"

        "and  %[tmp], %[val], #0xcccccccc\n\t"
        "and  %[val], %[val], #0x33333333\n\t"
        "add  %[val], %[val], %[tmp], lsr #2\n\t"

        "add  %[val], %[val], %[val], lsr #4\n\t"
        "and  %[val], %[val], #0x0f0f0f0f\n\t"

        "add  %[val], %[val], %[val], lsr #8\n\t"
        "add  %[val], %[val], %[val], lsr #16\n\t"
        "and  %[val], %[val], #63\n\t"
        : [val] "+l" (val), [tmp] "=&l" (tmp));
  return val;
}
#endif  // __arm__
