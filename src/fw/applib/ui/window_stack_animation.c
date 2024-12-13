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

#include "window_stack_animation.h"

#include "window_stack.h"
#include "window_stack_animation_rect.h"
#include "window_stack_animation_round.h"

void window_transition_context_appearance_call_all(WindowTransitioningContext *ctx) {
  window_transition_context_disappear(ctx);
  window_transition_context_appear(ctx);
}

const WindowTransitionImplementation *window_transition_get_default_push_implementation(void) {
#if PBL_RECT
  return &g_window_transition_default_push_implementation_rect;
#else
  return &g_window_transition_default_push_implementation_round.implementation;
#endif
}

const WindowTransitionImplementation *window_transition_get_default_pop_implementation(void) {
#if PBL_RECT
  return &g_window_transition_default_pop_implementation_rect;
#else
  return &g_window_transition_default_pop_implementation_round.implementation;
#endif
}
