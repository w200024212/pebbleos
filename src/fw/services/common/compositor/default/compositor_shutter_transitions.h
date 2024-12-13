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

// The length of first "section" of the animation, where the old app is moved off of the screen.
#define SHUTTER_TRANSITION_FIRST_DURATION_MS (2 * ANIMATION_TARGET_FRAME_INTERVAL_MS)
// The length of second "section" of the animation, where the new app is moved in.
#define SHUTTER_TRANSITION_SECOND_DURATION_MS (4 * ANIMATION_TARGET_FRAME_INTERVAL_MS)
// Total length of the animation.
#define SHUTTER_TRANSITION_DURATION_MS (SHUTTER_TRANSITION_FIRST_DURATION_MS + \
                                        SHUTTER_TRANSITION_SECOND_DURATION_MS)

const CompositorTransition *compositor_shutter_transition_get(
    CompositorTransitionDirection direction, GColor color);
