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

#pragma once

#include <inttypes.h>

// ratio32 - uint32 as a real number between 0 and 1

#define RATIO32_MIN 0
#define RATIO32_MAX 65535

static inline uint32_t ratio32_mul(uint32_t a, uint32_t b) {
  return (a * b) / RATIO32_MAX;
}

static inline uint32_t ratio32_div(uint32_t a, uint32_t b) {
  return (a * RATIO32_MAX) / b;
}

//! Converts a ratio32 to a percent in the range [0, 100]
static inline uint32_t ratio32_to_percent(uint32_t ratio) {
  return (ratio * 100) / RATIO32_MAX;
}

//! Converts a percent in the range [0, 100] to a ratio32
static inline uint32_t ratio32_from_percent(uint32_t percent) {
  return (percent * RATIO32_MAX) / 100 + 1;
}
