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

#include "services/normal/notifications/alerts_private.h"
#include "util/attributes.h"

AlertMask s_alert_mask;

AlertMask WEAK alerts_get_mask(void) {
  return s_alert_mask;
}

void WEAK alerts_set_mask(AlertMask mask) {
  s_alert_mask = mask;
}

uint32_t WEAK alerts_get_notification_window_timeout_ms(void) {
  return 0;
}

void WEAK alerts_incoming_alert_analytics() {}

void WEAK alerts_set_notification_vibe_timestamp() {}

bool WEAK alerts_should_enable_backlight_for_type(AlertType type) {
  return false;
}

bool WEAK alerts_should_notify_for_type(AlertType type) {
  return false;
}

bool WEAK alerts_should_vibrate_for_type(AlertType type) {
  return false;
}