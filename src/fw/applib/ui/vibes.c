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

#include "applib/ui/vibes.h"

#include "syscall/syscall.h"
#include "system/logging.h"
#include "util/size.h"

#define PATTERN_FROM_DURATIONS(pat, array) (pat) = (VibePattern){ .durations = (array), .num_segments = ARRAY_LENGTH((array)) }

static const uint32_t SHORT_PULSE_DURATIONS[] = { 250 };
static const uint32_t LONG_PULSE_DURATIONS[] = { 500 };
static const uint32_t DOUBLE_PULSE_DURATIONS[] = { 100, 100, 100 };

void vibes_short_pulse(void) {
  VibePattern pat;
  PATTERN_FROM_DURATIONS(pat, SHORT_PULSE_DURATIONS);
  vibes_enqueue_custom_pattern(pat);
}

void vibes_long_pulse(void) {
  VibePattern pat;
  PATTERN_FROM_DURATIONS(pat, LONG_PULSE_DURATIONS);
  vibes_enqueue_custom_pattern(pat);
}

void vibes_double_pulse(void) {
  VibePattern pat;
  PATTERN_FROM_DURATIONS(pat, DOUBLE_PULSE_DURATIONS);
  vibes_enqueue_custom_pattern(pat);
}

void vibes_cancel(void) {
  sys_vibe_pattern_clear();
}

void vibes_enqueue_custom_pattern(VibePattern pattern) {
  if (pattern.durations == NULL) {
    PBL_LOG(LOG_LEVEL_ERROR, "tried to enqueue a null pattern");
    return;
  }

  bool on = true;
  for (uint32_t i = 0; i < pattern.num_segments; ++i) {
    sys_vibe_pattern_enqueue_step(pattern.durations[i], on);
    on = !on;
  }

  sys_vibe_pattern_trigger_start();
}

