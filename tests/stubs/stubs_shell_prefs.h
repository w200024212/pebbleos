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

#include "shell/prefs.h"
#include "util/attributes.h"

static bool s_clock_24h;

bool WEAK shell_prefs_get_clock_24h_style(void) {
  return s_clock_24h;
}

void WEAK shell_prefs_set_clock_24h_style(bool is_24h) {
  s_clock_24h= is_24h;
}

static bool s_clock_timeezone_manual;

bool WEAK shell_prefs_is_timezone_source_manual(void) {
  return s_clock_timeezone_manual;
}

void WEAK shell_prefs_set_timezone_source_manual(bool manual) {
  s_clock_timeezone_manual = manual;
}

static int16_t s_timezone_id;

int16_t shell_prefs_get_automatic_timezone_id(void) {
  return s_timezone_id;
}

void shell_prefs_set_automatic_timezone_id(int16_t timezone_id) {
  s_timezone_id = timezone_id;
}

UnitsDistance WEAK shell_prefs_get_units_distance(void) {
  return UnitsDistance_Miles;
}

AppInstallId WEAK worker_preferences_get_default_worker(void) {
  return 0;
}

PreferredContentSize s_content_size = PreferredContentSizeDefault;

void WEAK system_theme_set_content_size(PreferredContentSize content_size) {
  s_content_size = content_size;
}

PreferredContentSize WEAK system_theme_get_content_size(void) {
  return (PreferredContentSize)s_content_size;
}
