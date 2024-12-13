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
#include "services/normal/timeline/timeline_actions.h"
#include "util/attributes.h"

void WEAK timeline_actions_add_action_to_root_level(TimelineItemAction *action,
                                                    ActionMenuLevel *root_level) {}

ActionMenuLevel *WEAK timeline_actions_create_action_menu_root_level(
    uint8_t num_actions, uint8_t separator_index, TimelineItemActionSource source) {
  return NULL;
}

ActionMenu *timeline_actions_push_action_menu(ActionMenuConfig *base_config,
                                              WindowStack *window_stack) {
  return NULL;
}

ActionMenu *WEAK timeline_actions_push_response_menu(
    TimelineItem *item, TimelineItemAction *reply_action, GColor bg_color,
    ActionMenuDidCloseCb did_close_cb, WindowStack *window_stack, TimelineItemActionSource source,
    bool standalone_reply) {
  return NULL;
};

void WEAK timeline_actions_cleanup_action_menu(ActionMenu *action_menu, const ActionMenuItem *item,
                                               void *context) {}

void WEAK timeline_actions_dismiss_all(
    NotificationInfo *notif_list, int num_notifications, ActionMenu *action_menu,
    ActionCompleteCallback dismiss_all_complete_callback, void *dismiss_all_cb_data) {}

void WEAK timeline_actions_invoke_action(const TimelineItemAction *action, const TimelineItem *pin,
                                         ActionCompleteCallback cb, void *cb_data) {}
