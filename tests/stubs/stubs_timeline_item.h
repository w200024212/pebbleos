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

#include "services/normal/timeline/item.h"

void WEAK timeline_item_destroy(TimelineItem* item) {}

void WEAK timeline_item_free_allocated_buffer(TimelineItem *item) { }

TimelineItem * WEAK timeline_item_create_with_attributes(time_t timestamp, uint16_t duration,
                                                         TimelineItemType type, LayoutId layout,
                                                         AttributeList *attr_list,
                                                         TimelineItemActionGroup *action_group) {
  return NULL;
}

bool WEAK timeline_item_action_is_ancs(const TimelineItemAction *action) {
  return false;
}

bool WEAK timeline_item_action_is_dismiss(const TimelineItemAction *action) {
  return false;
}

TimelineItemAction * WEAK timeline_item_find_dismiss_action(const TimelineItem *item) {
  return NULL;
}

bool WEAK timeline_item_is_ancs_notif(const TimelineItem *item) {
  return false;
}
