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

#include "rocky_api.h"

#include "applib/graphics/gtypes.h"
#include "jerry-api.h"

typedef struct RockyAPIGraphicsColorDefinition {
  const char *name;
  const uint8_t value;
} RockyAPIGraphicsColorDefinition;

bool rocky_api_graphics_color_parse(const char *color_value, GColor8 *parsed_color);

bool rocky_api_graphics_color_from_value(jerry_value_t value, GColor *parsed_color);
