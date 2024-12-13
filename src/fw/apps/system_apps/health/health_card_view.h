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

#include "health_data.h"

#include "applib/ui/ui.h"

//! Main structure for card view
typedef struct HealthCardView HealthCardView;


////////////////////////////////////////////////////////////////////////////////////////////////////
// API Functions
//

//! Creates a HealthCardView
//! @param health_data A pointer to the health data being given this view
//! @return A pointer to the newly allocated HealthCardView
HealthCardView *health_card_view_create(HealthData *health_data);

//! Destroy a HealthCardView
//! @param health_card_view A pointer to an existing HealthCardView
void health_card_view_destroy(HealthCardView *health_card_view);

//! Push a HealthCardView to the window stack
//! @param health_card_view A pointer to an existing HealthCardView
void health_card_view_push(HealthCardView *health_card_view);

//! Mark the card view as dirty so it is refreshed
//! @param health_card_view A pointer to an existing HealthCardView
void health_card_view_mark_dirty(HealthCardView *health_card_view);
