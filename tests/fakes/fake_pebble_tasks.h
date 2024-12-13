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

#include "stubs_worker_manager.h"

#include "kernel/pebble_tasks.h"

#include "FreeRTOS.h"
#include "task.h"

static PebbleTask s_current_task = PebbleTask_KernelMain;

PebbleTask pebble_task_get_current(void) {
  return s_current_task;
}

void stub_pebble_tasks_set_current(PebbleTask task) {
  s_current_task = task;
}

const char* pebble_task_get_name(PebbleTask task) {
  return "App <Stub>";
}

