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
#include "apps/system_apps/timeline/timeline.h"
#include "util/attributes.h"

void WEAK timeline_invoke_action(const TimelineItem *item, const TimelineItemAction *action,
                                 const AttributeList *attributes) {}

bool WEAK timeline_add_missed_call_pin(TimelineItem *pin, uint32_t uid) {
  return true;
}

bool WEAK timeline_add(TimelineItem *item) {
  return true;
}

bool WEAK timeline_remove(const Uuid *id) {
  return true;
}

bool WEAK timeline_exists(Uuid *id) {
  return true;
}

void WEAK timeline_action_endpoint_invoke_action(const Uuid *id, uint8_t action_id,
                                                 AttributeList *attributes) {}

Animation * WEAK timeline_animate_back_from_card(void) {
  return NULL;
}

bool WEAK timeline_get_originator_id(const TimelineItem *item, Uuid *id) {
  return false;
}
