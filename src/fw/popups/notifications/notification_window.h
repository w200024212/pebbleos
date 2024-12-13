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

#include <stdbool.h>
#include <stdint.h>

#include "applib/fonts/fonts.h"
#include "services/normal/notifications/notifications.h"
#include "kernel/events.h"

void notification_window_service_init(void);

void notification_window_init(bool is_modal);

void notification_window_show(void);

bool notification_window_is_modal(void);

void notification_window_handle_notification(PebbleSysNotificationEvent *e);

void notification_window_handle_reminder(PebbleReminderEvent *e);

void notification_window_handle_dnd_event(PebbleDoNotDisturbEvent *e);

void notification_window_add_notification_by_id(Uuid *id);

void notification_window_focus_notification(Uuid *id, bool animated);

void notification_window_mark_focused_read(void);

void app_notification_window_add_new_notification_by_id(Uuid *id);

void app_notification_window_remove_notification_by_id(Uuid *id);

void app_notification_window_handle_notification_acted_upon_by_id(Uuid *id);
