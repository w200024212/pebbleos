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

#include <stdbool.h>
#include <stdint.h>

typedef enum {
  ActionResultTypeSuccess,
  ActionResultTypeFailure,
  ActionResultTypeChaining,
  ActionResultTypeDoResponse,
  ActionResultTypeSuccessANCSDismiss,
} ActionResultType;

typedef struct {
  Uuid id;
  ActionResultType type;
  AttributeList attr_list;
  TimelineItemActionGroup action_group;
} PebbleSysNotificationActionResult;


void notifications_init(void);

//! Feedback for the result of an invoke action command
void notifications_handle_notification_action_result(
    PebbleSysNotificationActionResult *action_result);

//! Add a notification.
void notifications_handle_notification_added(Uuid *notification_id);

//! Handle a notification getting acted upon on the phone
void notifications_handle_notification_acted_upon(Uuid *notification_id);

//! Remove a notification
void notifications_handle_notification_removed(Uuid *notification_id);

//! Notify of remove command from ANCS. Notification will be kept in history
void notifications_handle_ancs_notification_removed(uint32_t ancs_uid);

//! Migration hook for notifications
//! Called with the GMT offset of the new timezone
void notifications_migrate_timezone(const int new_tz_offset);

//! Inserts a new notification into notification storage and notifies the system of the new item
//! @param notification Pointer to the notification to add
void notifications_add_notification(TimelineItem *notification);
