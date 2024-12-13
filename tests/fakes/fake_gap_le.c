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

#include "fake_gap_le.h"

#include <stdint.h>

bool gap_le_start_scan(void) {
  return true;
}

bool gap_le_stop_scan(void) {
  return true;
}

static bool s_gap_le_is_initialized = false;

void gap_le_init(uint32_t stack_id) {
  s_gap_le_is_initialized = true;
}

bool gap_le_deinit(uint32_t stack_id) {
  s_gap_le_is_initialized = false;
  return true;
}

void gap_le_connect_params_request_low_power(unsigned int stack_id, const BD_ADDR_t* addr) {

}

bool fake_gap_le_is_initialized(void) {
  return s_gap_le_is_initialized;
}

void sm_set_pairable(uint32_t stack_id, bool is_pairable) {
}

void gap_le_request_power_saving_connection_params(unsigned int stack_id, const BD_ADDR_t* addr) {
}

