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

#include "calendar_layout_resources.h"

#include "applib/graphics/gdraw_command_image.h"
#include "applib/graphics/gdraw_command_private.h"
#include "util/size.h"

// FIXME: PBL-28898 GPath algorithm requires strange coordinates for pixel perfection
// The paths here result in pixel perfect icons with the current gpath filled algorithm,
// but when gpath filled is fixed to correctly match its coordinates, these MUST be updated.

CalendarStartIcon g_calendar_start_icon = {
  .image = {
    .version = 1,
    .size = { 9, 9 },
    .command_list = {
      .num_commands = 1,
    },
  },
  .command = {
    .type = GDrawCommandTypePath,
    .fill_color = { .argb = GColorBlackARGB8 },
    .num_points = STATIC_ARRAY_LENGTH(GPoint, START_ICON_POINTS),
  },
  .points = START_ICON_POINTS,
};

CalendarEndIcon g_calendar_end_icon = {
  .image = {
    .version = 1,
    .size = { 9, 9 },
    .command_list = {
      .num_commands = 1,
    },
  },
  .command = {
    .type = GDrawCommandTypePath,
    .fill_color = { .argb = GColorBlackARGB8 },
    .num_points = STATIC_ARRAY_LENGTH(GPoint, END_ICON_POINTS),
  },
  .points = END_ICON_POINTS,
};
