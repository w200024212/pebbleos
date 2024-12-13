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

// Animation in design video lasts this many frames
#define ROUND_FLIP_ANIMATION_DURATION_MS (6 * ANIMATION_TARGET_FRAME_INTERVAL_MS)

void compositor_round_flip_transitions_flip_animation_update(GContext *ctx,
                                                             uint32_t distance_normalized,
                                                             CompositorTransitionDirection dir,
                                                             GColor flip_lid_color);

const CompositorTransition *compositor_round_flip_transition_get(bool flip_to_the_right);
