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

#include "item.h"
#include "layout_layer.h"
#include "timeline_layout.h"

#include "applib/graphics/gdraw_command_image.h"
#include "applib/graphics/graphics.h"
#include "applib/graphics/text.h"
#include "applib/ui/ui.h"

typedef enum {
  CalendarRecurringTypeNone = 0,
  CalendarRecurringTypeRecurring,
} CalendarRecurringType;

typedef struct {
  TimelineLayout timeline_layout;
  TextLayer date_layer;
  char day_date_buffer[TIME_STRING_DAY_DATE_LENGTH];
} CalendarLayout;

LayoutLayer *calendar_layout_create(const LayoutLayerConfig *config);

bool calendar_layout_verify(bool existing_attributes[]);
