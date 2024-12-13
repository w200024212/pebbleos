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

#include "applib/graphics/graphics_line.h"

void graphics_draw_line(GContext* ctx, GPoint p0, GPoint p1) {}

void graphics_line_draw_precise_stroked(GContext* ctx, GPointPrecise p0, GPointPrecise p1) {}

void graphics_line_draw_stroked_aa(GContext* ctx, GPoint p0, GPoint p1, uint8_t stroke_width) {}

void graphics_line_draw_stroked_non_aa(GContext* ctx, GPoint p0, GPoint p1, uint8_t stroke_width) {}
