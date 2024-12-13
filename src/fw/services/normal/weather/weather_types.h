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

//! Weather Types
//!
//! This file contains all the types for Weather Locations and Weather Data.
//! The weather_timestamp_utcs of all hourly data is exactly on the hour.
//! The weather_timestamp_utcs of all daily data is at midnight of the day.

#include "applib/graphics/gtypes.h"
#include "resource/timeline_resource_ids.auto.h"

// Do NOT add entries here. See weather_type_tuples.def
// TODO (PBL-36438): use proper enum naming
typedef enum {
#define WEATHER_TYPE_TUPLE(id, numeric_id, bg_color, text_color, timeline_resource_id)\
    WeatherType_##id = numeric_id,
#include "services/normal/weather/weather_type_tuples.def"
} WeatherType;

// ------------------------------------------------------------------------------------
const char *weather_type_get_name(WeatherType weather_type);

GColor weather_type_get_bg_color(WeatherType weather_type);

GColor weather_type_get_text_color(WeatherType weather_type);

TimelineResourceId weather_type_get_timeline_resource_id(WeatherType weather_type);
