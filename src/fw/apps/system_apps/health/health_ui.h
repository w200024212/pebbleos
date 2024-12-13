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

void health_ui_draw_text_in_box(GContext *ctx, const char *text, const GRect drawing_bounds,
                                const int16_t y_offset, const GFont small_font, GColor box_color,
                                GColor text_color);

void health_ui_render_typical_text_box(GContext *ctx, Layer *layer, const char *value_text);
