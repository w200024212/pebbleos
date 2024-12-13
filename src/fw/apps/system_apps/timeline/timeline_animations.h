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

#define TIMELINE_NUM_MOOOK_FRAMES_MID 3
#define TIMELINE_UP_DOWN_ANIMATION_DURATION_MS \
    (interpolate_moook_soft_duration(TIMELINE_NUM_MOOOK_FRAMES_MID))

int64_t timeline_animation_interpolate_moook_soft(int32_t normalized,
                                                  int64_t from, int64_t to);

int64_t timeline_animation_interpolate_moook_second_half(int32_t normalized,
                                                         int64_t from, int64_t to);

void timeline_animation_layer_stopped_cut_to_end(Animation *animation, bool finished,
                                                 void *context);
