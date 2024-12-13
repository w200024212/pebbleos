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

#include "popups/timeline/peek.h"
#include "services/normal/timeline/peek.h"
#include "util/attributes.h"

unsigned int WEAK timeline_peek_get_concurrent_height(unsigned int num_concurrent) {
  return 0;
}

int16_t WEAK timeline_peek_get_origin_y(void) {
  return DISP_ROWS;
}

int16_t WEAK timeline_peek_get_obstruction_origin_y(void) {
  return DISP_ROWS;
}

void WEAK timeline_peek_handle_process_start(void) {}

void WEAK timeline_peek_handle_process_kill(void) {}

void WEAK timeline_peek_set_show_before_time(unsigned int before_time_s) {};

bool WEAK timeline_peek_prefs_get_enabled() {
  return true;
}

uint16_t WEAK timeline_peek_prefs_get_before_time() {
  return (TIMELINE_PEEK_DEFAULT_SHOW_BEFORE_TIME_S / SECONDS_PER_MINUTE);
}

void WEAK timeline_peek_prefs_set_before_time(uint16_t before_time_m) {};

void WEAK peek_animations_draw_timeline_speed_lines(GContext *ctx, GPoint offset) {}
