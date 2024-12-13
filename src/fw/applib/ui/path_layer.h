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
#include "applib/graphics/gtypes.h"
#include "applib/graphics/gpath.h"
#include "applib/ui/layer.h"

typedef struct PathLayer {
  Layer layer;
  GPath path;
  GColor stroke_color;
  GColor fill_color;
} PathLayer;

void path_layer_init(PathLayer *path_layer, const GPathInfo *path_info);

void path_layer_deinit(PathLayer *path_layer, const GPathInfo *path_info);

void path_layer_set_stroke_color(PathLayer *path_layer, GColor color);

void path_layer_set_fill_color(PathLayer *path_layer, GColor color);

//! Gets the "root" Layer of the path layer, which is the parent for the sub-
//! layers used for its implementation.
//! @param path_layer Pointer to the PathLayer for which to get the "root" Layer
//! @return The "root" Layer of the path layer.
//! @internal
//! @note The result is always equal to `(Layer *) path_layer`.
Layer* path_layer_get_layer(const PathLayer *path_layer);

