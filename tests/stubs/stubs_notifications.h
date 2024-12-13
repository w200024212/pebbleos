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

#include "services/normal/notifications/notifications.h"

void notifications_init(void) {}

void notifications_handle_notification_action_result(
    PebbleSysNotificationActionResult *action_result) {}

void notifications_handle_notification_added(Uuid *notification_id) {}

void notifications_handle_notification_acted_upon(Uuid *notification_id) {}

void notifications_handle_notification_removed(Uuid *notification_id) {}

void notifications_handle_ancs_notification_removed(uint32_t ancs_uid) {}

void notifications_migrate_timezone(const int new_tz_offset) {}

void notifications_add_notification(TimelineItem *notification) {}
