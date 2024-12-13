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

typedef enum VibeIntensity {
  VibeIntensity_Stub
} VibeIntensity;

#define DEFAULT_VIBE_INTENSITY VibeIntensity_Stub

uint8_t get_strength_for_intensity(VibeIntensity intensity) {
  return 0;
}

VibeIntensity vibe_intensity_get(void) {
  return VibeIntensity_Stub;
}

void vibe_intensity_set(VibeIntensity intensity) {}
