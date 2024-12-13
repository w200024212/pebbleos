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

#include "services/normal/notifications/do_not_disturb.h"
#include "util/attributes.h"

bool WEAK do_not_disturb_is_active(void) {
  return false;
}

void WEAK do_not_disturb_init(void) {}

void WEAK do_not_disturb_manual_toggle_with_dialog(void) {}

void WEAK do_not_disturb_toggle_manually_enabled(ManualDNDFirstUseSource source) {}
