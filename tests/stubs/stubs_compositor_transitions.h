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

#include "services/common/compositor/compositor_transitions.h"
#include "util/attributes.h"

const CompositorTransition *WEAK compositor_slide_transition_timeline_get(
    bool timeline_is_future, bool timeline_is_destination, bool timeline_is_empty) {
  return NULL;
}

const CompositorTransition *WEAK compositor_dot_transition_timeline_get(
    bool timeline_is_future, bool timeline_is_destination) {
  return NULL;
}
