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

#include "applib/graphics/graphics.h"
#include "applib/graphics/text.h"
#include "apps/system_apps/timeline/text_node.h"

typedef enum {
  WeatherTimeType_None = 0,
  WeatherTimeType_Pin,
} WeatherTimeType;

typedef struct {
  TimelineLayout timeline_layout;
} WeatherLayout;

LayoutLayer *weather_layout_create(const LayoutLayerConfig *config);

bool weather_layout_verify(bool existing_attributes[]);
