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

#include "mfg/mfg_serials.h"
#include "applib/app_watch_info.h"
#include "applib/graphics/gtypes.h"

static const char *expected_serial_number = "2DQ0135B3424";

const char* mfg_get_serial_number(void) {
  return expected_serial_number;
}

void mfg_info_get_serialnumber(char *serial_number, size_t serial_number_size) {
  strncpy(serial_number, expected_serial_number, serial_number_size);
  if (serial_number_size > MFG_SERIAL_NUMBER_SIZE) {
    serial_number[MFG_SERIAL_NUMBER_SIZE] = '\0';
  }
}

static const char *expected_hw_version = "V2R2";
const char* mfg_get_hw_version(void) {
  return expected_hw_version;
}

WatchInfoColor mfg_info_get_watch_color(void) {
  return WATCH_INFO_COLOR_PINK;
}

GPoint mfg_info_get_disp_offsets(void) {
  return GPointZero;
}
