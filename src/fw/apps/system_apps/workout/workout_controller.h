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

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct WorkoutController {
  bool (*is_paused)(void);
  bool (*pause)(bool should_be_paused);
  bool (*stop)(void);

  void (*update_data)(void *data);
  void (*metric_to_string)(WorkoutMetricType type, char *buffer,
                           size_t buffer_size, void *i18n_owner, void *workout_data);
  int32_t (*get_metric_value)(WorkoutMetricType type, void *data);
  const char* (*get_distance_string)(const char *miles_string, const char *km_string);
  char* (*get_custom_metric_label_string)(void);
} WorkoutController;
