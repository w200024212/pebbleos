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

#define PORT_HOLE_TRANSITION_DURATION_MS (6 * ANIMATION_TARGET_FRAME_INTERVAL_MS)

const CompositorTransition *compositor_port_hole_transition_app_get(
  CompositorTransitionDirection direction);

void compositor_port_hole_transition_draw_outer_ring(GContext *ctx, int16_t pixels,
                                                     GColor ring_color);
