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

#include "fake_gap_le_connect_params.h"

#include "GAPAPI.h"

static ResponseTimeState s_last_requested_desired_state;

void gap_le_connect_params_request(GAPLEConnection *connection,
                                   ResponseTimeState desired_state) {
  s_last_requested_desired_state = desired_state;
}

void gap_le_connect_params_setup_connection(GAPLEConnection *connection) {
}

void gap_le_connect_params_cleanup_by_connection(GAPLEConnection *connection) {
}

void gap_le_connect_params_handle_update(unsigned int stack_id,
                                    const GAP_LE_Connection_Parameter_Updated_Event_Data_t *event) {
}

void gap_le_connect_params_handle_connection_parameter_update_response(
                       const GAP_LE_Connection_Parameter_Update_Response_Event_Data_t *event_data) {
}

static ResponseTimeState s_actual_state;
ResponseTimeState gap_le_connect_params_get_actual_state(GAPLEConnection *connection) {
  return s_actual_state;
}

void fake_gap_le_connect_params_init(void) {
  s_last_requested_desired_state = ResponseTimeInvalid;
  s_actual_state = ResponseTimeInvalid;
}

ResponseTimeState fake_gap_le_connect_params_get_last_requested(void) {
  return s_last_requested_desired_state;
}

void fake_gap_le_connect_params_reset_last_requested(void) {
  s_last_requested_desired_state = ResponseTimeInvalid;
}

void fake_gap_le_connect_params_set_actual_state(ResponseTimeState actual_state) {
  s_actual_state = actual_state;
}
