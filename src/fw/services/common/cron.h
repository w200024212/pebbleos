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

#include "kernel/events.h"

//! @file cron.h
//! Wall-clock based timer system. Designed for use in things such as alarms, calendar events, etc.
//! Properly handles DST, etc.
//! This file is for controlling the service itself. The actual job API is in <pebbleos/cron.h>

//! Initialize the cron service.
void cron_service_init(void);

//! Adjust all cron jobs, as the wall clock has changed.
//! This means DST and/or time zone may have changed!
void cron_service_handle_clock_change(PebbleSetTimeEvent *set_time_info);

#if UNITTEST
// -----------------------------------------------------------------------------
// For testing:

//! Remove all jobs.
void cron_clear_all_jobs(void);

//! Clean up the cron service.
void cron_service_deinit(void);

//! The number of registered cron jobs.
uint32_t cron_service_get_job_count(void);

//! Run the cron timers if they've fired.
void cron_service_wakeup(void);
#endif
