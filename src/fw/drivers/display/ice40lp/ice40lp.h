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

#include "../display.h"

typedef enum {
  DISP_COLOR_BLACK = 0,
  DISP_COLOR_WHITE,
  DISP_COLOR_RED,
  DISP_COLOR_GREEN,
  DISP_COLOR_BLUE,
  DISP_COLOR_MAX
} DispColor;

static const uint8_t s_display_colors[DISP_COLOR_MAX] = { 0x00, 0xff, 0xc0, 0x30, 0x0c };

void display_fill_color(uint8_t color_value);
void display_fill_stripes();
