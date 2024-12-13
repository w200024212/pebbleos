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

#include "services/normal/notifications/alerts.h"

typedef enum AlertMask {
  AlertMaskAllOff       = 0,
  AlertMaskPhoneCalls   = NotificationPhoneCall,
  AlertMaskOther        = NotificationOther,
  AlertMaskAllOnLegacy  =
    NotificationMobile | NotificationPhoneCall | NotificationOther,
  AlertMaskAllOn        =
    NotificationMobile | NotificationPhoneCall | NotificationOther | NotificationReminder
} AlertMask;

bool alerts_get_vibrate(void);

AlertMask alerts_get_mask(void);

AlertMask alerts_get_dnd_mask(void);

uint32_t alerts_get_notification_window_timeout_ms(void);

void alerts_set_vibrate(bool enable);

void alerts_set_mask(AlertMask mask);

void alerts_set_dnd_mask(AlertMask mask);

void alerts_set_notification_window_timeout_ms(uint32_t timeout_ms);

void alerts_init(void);
