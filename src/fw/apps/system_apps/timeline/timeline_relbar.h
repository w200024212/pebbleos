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

#include "timeline_layer.h"
#include "applib/ui/animation.h"

typedef enum {
  RelationshipBarOffsetTypePrev,
  RelationshipBarOffsetTypeCurr,
  RelationshipBarOffsetTypeBoth
} RelationshipBarOffsetType;

//! Create the animations for the relationship bars
//! @param layer Pointer to the \ref TimelineLayer to create the relationship bar animation for
//! @param duration Duration in ms of the animation to create
//! @param interpolate Custom interpolation function to use for the animation
Animation *timeline_relbar_layer_create_animation(TimelineLayer *timeline_layer, uint32_t duration,
                                                  InterpolateInt64Function interpolate);

//! Reset the relationship bar state
void timeline_relbar_layer_reset(TimelineLayer *timeline_layer);

//! Initialize the timeline relationship bar layer within the \ref TimelineLayer
void timeline_relbar_layer_init(TimelineLayer *timeline_layer);

//! Deinitialize the timeline relationship bar layer within the \ref TimelineLayer
void timeline_relbar_layer_deinit(TimelineLayer *timeline_layer);
