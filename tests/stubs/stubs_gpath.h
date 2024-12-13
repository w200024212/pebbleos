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

#include "applib/graphics/gpath.h"

void gpath_init(GPath *path, const GPathInfo *init) {}

void gpath_move_to(GPath *path, GPoint point) {}

void gpath_draw_stroke(GContext* ctx, GPath* path, bool open) {}

void gpath_draw_filled(GContext* ctx, GPath *path) {}

void gpath_fill_precise_internal(GContext *ctx, GPointPrecise *points, size_t num_points) {}

void gpath_draw_outline_precise_internal(GContext *ctx, GPointPrecise *points, size_t num_points,
                                         bool open) {}

GRect gpath_outer_rect(GPath *path) {
  return (GRect) {};
}
