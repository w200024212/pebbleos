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
#include "jerry-api.h"

#include "applib/graphics/text.h"

void rocky_api_graphics_text_init(void);
void rocky_api_graphics_text_deinit(void);
void rocky_api_graphics_text_add_canvas_methods(jerry_value_t obj);
void rocky_api_graphics_text_reset_state(void);

// these structs are exposed here so that we can unit-test the internal state
typedef struct RockyAPISystemFontDefinition {
  const char *js_name;
  const char *res_key;
} RockyAPISystemFontDefinition;

typedef struct RockyAPITextState {
  GFont font;
  const char *font_name;
  GTextOverflowMode overflow_mode;
  GTextAlignment alignment;
  GTextAttributes *text_attributes;
} RockyAPITextState;
