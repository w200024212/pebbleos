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

#include "comm/ble/kernel_le_client/ancs/ancs_types.h"

bool nexmo_is_reauth_sms(const ANCSAttribute *app_id, const ANCSAttribute *message) {
  return false;
}

void nexmo_handle_reauth_sms(uint32_t uid,
                             const ANCSAttribute *app_id,
                             const ANCSAttribute *message,
                             iOSNotifPrefs *existing_notif_prefs) {
  return;
}
