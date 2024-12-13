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

#include "services/normal/activity/activity.h"
#include "services/normal/activity/hr_util.h"

#include <stdint.h>
#include <stdbool.h>

bool workout_service_is_workout_ongoing(void);

bool workout_service_start_workout(ActivitySessionType type);

bool workout_service_pause_workout(bool should_be_paused);

bool workout_service_stop_workout(void);

bool workout_service_is_paused(void);

bool workout_service_get_current_workout_type(ActivitySessionType *type_out);

bool workout_service_get_current_workout_info(int32_t *steps_out, int32_t *duration_s_out,
                                              int32_t *distance_m_out, int32_t *current_bpm_out,
                                              HRZone *current_hr_zone_out);

bool workout_service_set_current_workout_info(int32_t steps, int32_t duration_s,
                                              int32_t distance_m, int32_t current_bpm,
                                              HRZone current_hr_zone);
