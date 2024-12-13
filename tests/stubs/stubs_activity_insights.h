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

#include <stdint.h>

#include "util/time/time.h"

void activity_insights_recalculate_stats(void) {
  return;
}

void activity_insights_init(time_t now_utc) {
  return;
}

void activity_insights_process_sleep_data(time_t now_utc) {
  return;
}

void activity_insights_process_minute_data(time_t now_utc) {
  return;
}

void activity_insights_start_activity_session(time_t start_utc, uint32_t distance_mm,
                                              uint32_t calories) {
  return;
}

void activity_insights_push_activity_session(time_t start_utc, uint32_t elapsed_min, int32_t steps,
                                             uint32_t distance_mm, uint32_t calories) {
  return;
}

void activity_insights_push_activity_session_notification(time_t notif_time,
                                                          ActivitySession *session,
                                                          int32_t avg_hr,
                                                          int32_t *hr_zone_time_s) {
  return;
}
