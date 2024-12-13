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

#include "services/normal/activity/activity_private.h"
#include "util/attributes.h"

bool WEAK activity_tracking_on(void) {
  return true;
}

bool WEAK activity_get_metric(ActivityMetric metric, uint32_t history_len, int32_t *history) {
  return false;
}

bool WEAK activity_get_sessions(uint32_t *session_entries, ActivitySession *sessions) {
  return false;
}

bool WEAK activity_get_step_averages(DayInWeek day_of_week, ActivityMetricAverages *averages) {
  return false;
}

void WEAK activity_metrics_prv_set_metric(ActivityMetric metric, DayInWeek day, int32_t value) {}

bool WEAK activity_prefs_tracking_is_enabled(void) {
  return false;
}

uint8_t WEAK activity_prefs_get_age_years(void) {
  return 30; // This is our current default
}

bool WEAK activity_prefs_heart_rate_is_enabled(void) {
  return true;
}

bool activity_get_metric_typical(ActivityMetric metric, DayInWeek day, int32_t *value_out) {
  return false;
}

bool activity_get_metric_monthly_avg(ActivityMetric metric, int32_t *value_out) {
  return false;
}

uint32_t activity_private_compute_distance_mm(uint32_t steps, uint32_t ms) {
  return 0;
}

uint32_t activity_private_compute_active_calories(uint32_t distance_mm, uint32_t ms) {
  return 0;
}

uint32_t activity_private_compute_resting_calories(uint32_t elapsed_minutes) {
  return 0;
}

uint8_t activity_prefs_heart_get_resting_hr(void) {
  return 70;
}

uint8_t activity_prefs_heart_get_elevated_hr(void) {
  return 100;
}

uint8_t activity_prefs_heart_get_max_hr(void) {
  return 190;
}

uint8_t activity_prefs_heart_get_zone1_threshold(void) {
  return 130;
}

uint8_t activity_prefs_heart_get_zone2_threshold(void) {
  return 154;
}

uint8_t activity_prefs_heart_get_zone3_threshold(void) {
  return 172;
}
