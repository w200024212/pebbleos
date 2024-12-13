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

typedef enum {
  SleepSummaryView_Sleep,
  SleepSummaryView_DeepSleep,
  SleepSummaryView_EndAndWake,
  SleepSummaryView_Nap,
  SleepSummaryViewCount
} SleepSummaryView;

////////////////////////////////////////////////////////////////////////////////////////////////////
// API Functions
//

//! Creates a layer with extra data
//! @param health_data A pointer to the health data buffer
//! @return A pointer to the newly allocated layer
Layer *health_sleep_summary_card_create(HealthData *health_data);

//! Health activity summary select click handler
//! @param layer A pointer to an existing layer with extra data
void health_sleep_summary_card_select_click_handler(Layer *layer);

//! Set the card to a given view
//! @param view the view type to show
void health_sleep_summary_card_set_view(Layer *layer, SleepSummaryView view);

//! Destroy a layer with extra data
//! @param base_layer A pointer to an existing layer with extra data
void health_sleep_summary_card_destroy(Layer *base_layer);

//! Health sleep summary layer background color getter
GColor health_sleep_summary_card_get_bg_color(Layer *layer);

//! Health sleep summary layer should show select click indicator
bool health_sleep_summary_show_select_indicator(Layer *layer);
