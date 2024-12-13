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

#include "services/common/compositor/compositor.h"

// These numbers approximate the visuals shown in the videos from the design team
#define STATIC_DOT_ANIMATION_DURATION_MS 233
#define DOT_ANIMATION_STROKE_WIDTH 12

void compositor_dot_transitions_collapsing_ring_animation_update(GContext *ctx,
                                                                 uint32_t distance_normalized,
                                                                 GColor outer_ring_color,
                                                                 GColor inner_ring_color);

const CompositorTransition* compositor_dot_transition_timeline_get(bool timeline_is_future,
                                                                   bool timeline_is_destination);

const CompositorTransition* compositor_dot_transition_app_fetch_get(void);
