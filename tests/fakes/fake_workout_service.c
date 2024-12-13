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

#include "fake_workout_service.h"

static bool s_is_paused;
static bool s_is_ongoing;
static int32_t s_steps;
static int32_t s_duration_s;
static int32_t s_distance_m;
static int32_t s_current_bpm;
static int32_t s_current_hr_zone;

bool workout_service_is_workout_ongoing(void) {
  return s_is_ongoing;
}

bool workout_service_start_workout(ActivitySessionType type) {
  s_is_ongoing = true;
  return true;
}

bool workout_service_pause_workout(bool should_be_paused) {
  s_is_paused = should_be_paused;
  return true;
}

bool workout_service_stop_workout(void) {
  s_is_ongoing = false;
  return true;
}

bool workout_service_is_paused(void) {
  return s_is_paused;
}

bool workout_service_get_current_workout_type(ActivitySessionType *type_out) {
  return false;
}

bool workout_service_get_current_workout_info(int32_t *steps_out, int32_t *duration_s_out,
                                              int32_t *distance_m_out, int32_t *current_bpm_out,
                                              HRZone *current_hr_zone_out) {
  *steps_out = s_steps;
  *duration_s_out = s_duration_s;
  *distance_m_out = s_distance_m;
  *current_bpm_out = s_current_bpm;
  *current_hr_zone_out = s_current_hr_zone;

  return true;
}

bool workout_service_set_current_workout_info(int32_t steps, int32_t duration_s,
                                              int32_t distance_m, int32_t current_bpm,
                                              HRZone current_hr_zone) {
  s_steps = steps;
  s_duration_s = duration_s;
  s_distance_m = distance_m;
  s_current_bpm = current_bpm;
  s_current_hr_zone = current_hr_zone;

  return true;
}
