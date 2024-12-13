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

#include "applib/ui/animation_timing.h"
#include "util/attributes.h"

AnimationProgress WEAK animation_timing_segmented(
    AnimationProgress time_normalized, int32_t index, uint32_t num_segments,
    Fixed_S32_16 duration_fraction) {
  return time_normalized;
}

AnimationProgress WEAK animation_timing_curve(AnimationProgress time_normalized,
                                              AnimationCurve curve) {
  return time_normalized;
}

AnimationProgress WEAK animation_timing_scaled(AnimationProgress time_normalized,
                                               AnimationProgress interval_start,
                                               AnimationProgress interval_end) {
  return interval_end;
}

