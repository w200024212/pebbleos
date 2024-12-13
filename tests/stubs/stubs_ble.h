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

#include "stubs_bluetooth_pairing_ui.h"
#include "stubs_events.h"
#include "stubs_HCIAPI.h"
#include "stubs_L2CAPAPI.h"
#include "stubs_hexdump.h"
#include "stubs_queue.h"

#include <inttypes.h>
#include <stdbool.h>

bool gaps_init(void) {
  return true;
}

bool gaps_deinit(uint32_t stack_id) {
  return true;
}

void comm_handle_paired_devices_changed(void) {
}
