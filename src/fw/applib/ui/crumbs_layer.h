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

#include "applib/ui/animation.h"
#include "applib/ui/layer.h"
#include "applib/graphics/graphics.h"

typedef struct {
  Layer layer;
  int level;
  GColor bg_color;
  GColor fg_color;
  // used internally
  int16_t crumbs_x_increment;
} CrumbsLayer;

void crumbs_layer_init(CrumbsLayer *crumbs_layer, const GRect *frame, GColor fg_color,
                       GColor bg_color);

CrumbsLayer *crumbs_layer_create(GRect frame, GColor fg_color, GColor bg_color);

void crumbs_layer_set_level(CrumbsLayer *crumbs_layer, int level);

void crumbs_layer_deinit(CrumbsLayer *crumbs_layer);

void crumbs_layer_destroy(CrumbsLayer *crumbs_layer);

Animation *crumbs_layer_get_animation(CrumbsLayer *crumbs_layer);

int crumbs_layer_width(void);
