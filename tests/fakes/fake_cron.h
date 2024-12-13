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

#include <pebbleos/cron.h>

#include "clar_asserts.h"

static CronJob *s_job = NULL;

time_t cron_job_schedule(CronJob *job) {
  s_job = job;
  return 0;
}

bool cron_job_unschedule(CronJob *job) {
  s_job = NULL;
  return true;
}

void fake_cron_job_fire(void) {
  cl_assert(s_job != NULL);
  CronJob *job = s_job;
  s_job = NULL;
  job->cb(job, job->cb_data);
}

