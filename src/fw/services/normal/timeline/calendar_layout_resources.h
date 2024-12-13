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

#include "applib/graphics/gdraw_command_image.h"
#include "applib/graphics/gdraw_command_private.h"
#include "util/attributes.h"
#include "util/size.h"

#define START_ICON_POINTS { { 0, -2 }, { 9, 4 }, { 0, 10 } }

typedef struct PACKED {
  struct {
    GDrawCommandImage image;
  };
  GDrawCommand command;
  GPoint points[STATIC_ARRAY_LENGTH(GPoint, START_ICON_POINTS)];
} CalendarStartIcon;

extern CalendarStartIcon g_calendar_start_icon;

#define END_ICON_POINTS { { 0, 0 }, { 10, 0 }, { 10, 8 }, { 0, 8 } }

typedef struct PACKED {
  struct {
    GDrawCommandImage image;
  };
  GDrawCommand command;
  GPoint points[STATIC_ARRAY_LENGTH(GPoint, END_ICON_POINTS)];
} CalendarEndIcon;

extern CalendarEndIcon g_calendar_end_icon;
