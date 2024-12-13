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
#include "applib/ui/progress_layer.h"

#include <stdint.h>
#include <stdbool.h>

#define LOADING_LAYER_DEFAULT_SIZE { 79, PROGRESS_SUGGESTED_HEIGHT }

typedef void (*LoadingLayerAnimCompleteCb)(void *context);

typedef struct {
  ProgressLayer progress_layer;
  Animation *animation;
  GRect full_frame;
} LoadingLayer;

void loading_layer_init(LoadingLayer *loading_layer, const GRect *frame);

void loading_layer_deinit(LoadingLayer *loading_layer);

void loading_layer_shrink(LoadingLayer *loading_layer, uint32_t delay, uint32_t duration,
                          AnimationStoppedHandler stopped_handler, void *context);

void loading_layer_grow(LoadingLayer *loading_layer, uint32_t duration, uint32_t delay);

void loading_layer_pause(LoadingLayer *loading_layer);
