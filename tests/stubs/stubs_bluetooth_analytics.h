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

#include "GAPAPI.h"

#include <stdbool.h>

void bluetooth_analytics_get_param_averages(uint16_t *params) {
}

void bluetooth_analytics_handle_connection_params_update(
                                             const GAP_LE_Current_Connection_Parameters_t *params) {
}

void bluetooth_analytics_handle_connect(unsigned int stack_id,
                                             const GAP_LE_Connection_Complete_Event_Data_t *event) {
}

void bluetooth_analytics_handle_disconnect(bool local_is_master) {
}

void bluetooth_analytics_handle_encryption_change(void) {
}

void bluetooth_analytics_handle_no_intent_for_connection(void) {
}
