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

#include "window_stack_animation.h"

#include "services/common/compositor/compositor.h"

typedef struct {
  WindowTransitionImplementation implementation;
  CompositorTransitionDirection transition_direction;
} WindowTransitionRoundImplementation;

extern const WindowTransitionRoundImplementation
  g_window_transition_default_push_implementation_round;
extern const WindowTransitionRoundImplementation
  g_window_transition_default_pop_implementation_round;
