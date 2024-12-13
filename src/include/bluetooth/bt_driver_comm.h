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

typedef struct CommSession CommSession;

//! Figures out the optimal thread to execute `bt_driver_run_send_next_job` on
//! and schedules a job to do so
bool bt_driver_comm_schedule_send_next_job(CommSession *session);

//! @return The PebbleTask that is used with bt_driver_comm_schedule_send_next_job() to perform
//! the sending of pending data.
bool bt_driver_comm_is_current_task_send_next_task(void);

extern void bt_driver_run_send_next_job(CommSession *session, bool is_callback);
