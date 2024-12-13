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

#include "workout_controller.h"
#include "workout_metrics.h"

#include "services/normal/activity/activity.h"

typedef struct WorkoutActiveWindow WorkoutActiveWindow;


WorkoutActiveWindow *workout_active_create_single_layout(WorkoutMetricType metric,
                                                         void *workout_data,
                                                         WorkoutController *workout_controller);

WorkoutActiveWindow *workout_active_create_double_layout(WorkoutMetricType top_metric,
                                                         int num_scrollable_metrics,
                                                         WorkoutMetricType *scrollable_metrics,
                                                         void *workout_data,
                                                         WorkoutController *workout_controller);

WorkoutActiveWindow *workout_active_create_tripple_layout(WorkoutMetricType top_metric,
                                                          WorkoutMetricType middle_metric,
                                                          int num_scrollable_metrics,
                                                          WorkoutMetricType *scrollable_metrics,
                                                          void *workout_data,
                                                          WorkoutController *workout_controller);

WorkoutActiveWindow *workout_active_create_for_activity_type(ActivitySessionType type,
                                                             void *workout_data,
                                                             WorkoutController *workout_controller);

void workout_active_window_push(WorkoutActiveWindow *window);

void workout_active_update_scrollable_metrics(WorkoutActiveWindow *active_window,
                                              int num_scrollable_metrics,
                                              WorkoutMetricType *scrollable_metrics);
