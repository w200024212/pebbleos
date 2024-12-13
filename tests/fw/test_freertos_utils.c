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

#include "os/tick.h"

#include "FreeRTOS.h"

#include <stdlib.h>
#include <string.h>

#include "clar.h"

// Stubs
///////////////////////////////////////////////////////////
#include "stubs_passert.h"
#include "stubs_logging.h"
#include "stubs_tick.h"

// Tests
///////////////////////////////////////////////////////////

static const double s_tick_rate_hz = configTICK_RATE_HZ;

static double milliseconds_to_ticks_double(double milliseconds) {
  return (milliseconds * s_tick_rate_hz) / 1000.0;
}

void test_freertos_utils__should_convert_48h_to_ticks(void) {
  uint32_t time_ms = 24 * 7 * 60 * 60 * 1000;
  cl_assert_equal_i(milliseconds_to_ticks(time_ms), (uint32_t)milliseconds_to_ticks_double(time_ms));
}

void test_freertos_utils__should_convert_max_to_ticks(void) {
  const uint32_t uint32_max = ~0;

  // The maximum input time possible until overflow
  uint32_t max_time_ms = ((double)uint32_max * 1000.0) / s_tick_rate_hz;

  cl_assert(milliseconds_to_ticks(max_time_ms) == (uint32_max - 1));
  cl_assert(milliseconds_to_ticks(max_time_ms) == (uint32_t)milliseconds_to_ticks_double(max_time_ms));
}
