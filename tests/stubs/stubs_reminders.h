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

#include "system/status_codes.h"
#include "util/attributes.h"

status_t WEAK reminders_update_timer(void) {
  return S_SUCCESS;
}

status_t WEAK reminders_init(void) {
  return S_SUCCESS;
}

void WEAK reminders_handle_reminder_updated(const Uuid *reminder_id) {
  return;
}

bool WEAK reminders_can_snooze(Reminder *reminder) {
  return false;
}

status_t WEAK reminders_snooze(Reminder *reminder) {
  return S_SUCCESS;
}
