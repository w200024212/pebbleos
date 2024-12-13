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

#include <stdbool.h>
#include <stdint.h>

typedef enum {
  SmartstrapStateUnsubscribed,
  SmartstrapStateReadReady,
  SmartstrapStateNotifyInProgress,
  SmartstrapStateReadDisabled,
  SmartstrapStateReadInProgress,
  SmartstrapStateReadComplete
} SmartstrapState;


SmartstrapState smartstrap_fsm_state_get(void);
void smartstrap_fsm_state_reset(void);
bool smartstrap_fsm_state_test_and_set(SmartstrapState expected_state, SmartstrapState next_state);
void smartstrap_fsm_state_set(SmartstrapState next_state);
void smartstrap_state_lock(void);
void smartstrap_state_unlock(void);
void smartstrap_state_assert_locked_by_current_task(void);
bool sys_smartstrap_is_service_connected(uint16_t service_id);
