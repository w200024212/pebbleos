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

#include "workout_metrics.h"

#include "services/normal/activity/hr_util.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct WorkoutData {
  int32_t steps;
  int32_t duration_s;
  int32_t distance_m;
  int32_t avg_pace;
  int32_t bpm;
  HRZone hr_zone;
} WorkoutData;

void workout_data_update(void *workout_data);

void workout_data_fill_metric_value(WorkoutMetricType type, char *buffer,
                                    size_t buffer_size, void *i18n_owner, void *workout_data);

int32_t workout_data_get_metric_value(WorkoutMetricType type, void *workout_data);
