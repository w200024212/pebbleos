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

#include "util/math.h"

#include <stdint.h>
#include <stdbool.h>

int ceil_log_two(uint32_t n) {
    // clz stands for Count Leading Zeroes. We use it to find the MSB
    int msb = 31 - __builtin_clz(n);
    // popcount counts the number of set bits in a word (1's)
    bool power_of_two = __builtin_popcount(n) == 1;
    // if not exact power of two, use the next power of two
    // we want to err on the side of caution and want to
    // always round up
    return ((power_of_two) ? msb : (msb + 1));
}
