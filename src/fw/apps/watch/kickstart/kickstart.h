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

#include "applib/ui/ui.h"
#include "process_management/pebble_process_md.h"

typedef struct KickstartData {
  Window window;
  Layer base_layer;

  int32_t current_steps;
  int32_t typical_steps;
  int32_t daily_steps_avg;
  int32_t current_bpm;

#if PBL_BW
  GBitmap shoe;
#else
  GBitmap shoe_blue;
  GBitmap shoe_green;
#endif
#if PBL_COLOR && PBL_DISPLAY_WIDTH == 144 && PBL_DISPLAY_HEIGHT == 168
  GBitmap shoe_blue_small;
  GBitmap shoe_green_small;
#endif
  GBitmap heart_icon;

  GFont steps_font;
  GFont time_font;
  GFont am_pm_font;

  bool screen_is_obstructed;
  char steps_buffer[8];
} KickstartData;

const PebbleProcessMd* kickstart_get_app_info();
