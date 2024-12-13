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

#include "popups/timeline/timeline_item_layer.h"
#include "services/normal/timeline/timeline.h"

#include "applib/ui/ui.h"

typedef struct TimelinePinWindow TimelinePinWindow;

struct TimelinePinWindow {
  Window window;
  Layer layer; //!< Used to perform a bounds animation of the window
  Layer action_button_layer;
  StatusBarLayer status_layer;
  TimelineItemLayer item_detail_layer;
  TimelineLayoutInfo info;
  Animation *pop_animation;
  EventServiceInfo blobdb_event_info; //!< Used for pin events when in modal window
};

void timeline_pin_window_set_item(TimelinePinWindow *pin_window, TimelineItem *item,
                                  time_t current_day);

//! Pop the timeline pin window
void timeline_pin_window_pop(TimelinePinWindow *pin_window);

void timeline_pin_window_init(TimelinePinWindow *pin_window, TimelineItem *item,
                              time_t current_day);

void timeline_pin_window_push_modal(TimelineItem *item);
