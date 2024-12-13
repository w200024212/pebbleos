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

//! @file compositor_modal_transitions.h
//! Allows a user to create and configure compositor transition animations for modals.

//! @param modal_is_destination Whether the animation should animate to the modal or not
//! @return \ref CompositorTransition for the requested modal animation
const CompositorTransition* compositor_modal_transition_to_modal_get(bool modal_is_destination);
