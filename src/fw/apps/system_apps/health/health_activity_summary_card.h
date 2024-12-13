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


////////////////////////////////////////////////////////////////////////////////////////////////////
// API Functions
//

//! Creates a special layer with data
//! @param health_data A pointer to the health data being given this card
//! @return A pointer to a newly allocated layer, which contains its own data
Layer *health_activity_summary_card_create(HealthData *health_data);

//! Health activity summary select click handler
//! @param layer A pointer to an existing layer containing its own data
void health_activity_summary_card_select_click_handler(Layer *layer);

//! Destroy a special layer
//! @param base_layer A pointer to an existing layer containing its own data
void health_activity_summary_card_destroy(Layer *base_layer);

//! Health activity summary layer background color getter
GColor health_activity_summary_card_get_bg_color(Layer *layer);

//! Health activity summary layer select click is available
bool health_activity_summary_show_select_indicator(Layer *layer);
