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

#include "applib/accel_service_private.h"

void accel_service_state_init(AccelServiceState *state) {
}

void accel_data_service_subscribe(uint32_t samples_per_update, AccelDataHandler handler) {
}

void accel_raw_data_service_subscribe(uint32_t samples_per_update, AccelRawDataHandler handler) {
}

void accel_data_service_unsubscribe(void) {
}

AccelServiceState* accel_service_private_get_session(PebbleTask task) {
  return NULL;
}

void accel_service_cleanup_task_session(PebbleTask task) {
}
