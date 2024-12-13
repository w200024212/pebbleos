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

typedef struct {
  uint8_t hour;
  uint8_t minute;
} TimeData;

typedef enum {
  TimeInputIndexHour = 0,
  TimeInputIndexMinute,
  TimeInputIndexAMPM,
} TimeInputIndex;

typedef enum {
  DateInputIndexYear = 0,
  DateInputIndexMonth,
  DateInputIndexDay,
} DateInputIndex;

int date_time_selection_step_hour(int hour, int delta);

int date_time_selection_step_minute(int minute, int delta);

int date_time_selection_step_day(int year, int month, int day, int delta);

int date_time_selection_step_month(int month, int delta);

int date_time_selection_truncate_date(int year, int month, int day);

int date_time_selection_step_year(int year, int delta);

char *date_time_selection_get_text(TimeData *data, TimeInputIndex index, char *buf);

void date_time_handle_time_change(TimeData *data, TimeInputIndex index, int delta);
