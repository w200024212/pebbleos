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

#include "clar.h"

#include "services/normal/vibes/vibe_intensity.h"

// Stubs
/////////

#include "stubs_alerts_preferences.h"
#include "stubs_vibe_pattern.h"

// Setup and Teardown
//////////////////////

void test_vibe_intensity__initialize(void) {
}

void test_vibe_intensity__cleanup(void) {
}

// Tests
/////////

void test_vibe_intensity__get_string_for_intensity(void) {
  // A bogus intensity returns NULL
  cl_assert_equal_p(vibe_intensity_get_string_for_intensity(VibeIntensityNum), NULL);

  cl_assert_equal_s(vibe_intensity_get_string_for_intensity(VibeIntensityLow), "Standard - Low");
  cl_assert_equal_s(vibe_intensity_get_string_for_intensity(VibeIntensityMedium),
                    "Standard - Medium");
  cl_assert_equal_s(vibe_intensity_get_string_for_intensity(VibeIntensityHigh), "Standard - High");
}

void test_vibe_intensity__cycle_next(void) {
  // Low -> Medium
  cl_assert(vibe_intensity_cycle_next(VibeIntensityLow) == VibeIntensityMedium);

  // Medium -> High
  cl_assert(vibe_intensity_cycle_next(VibeIntensityMedium) == VibeIntensityHigh);

  // High -> Low
  cl_assert(vibe_intensity_cycle_next(VibeIntensityHigh) == VibeIntensityLow);
}
