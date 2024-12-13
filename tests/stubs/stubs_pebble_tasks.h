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

#include "kernel/pebble_tasks.h"

#include "FreeRTOS.h"
#include "task.h"

PebbleTask pebble_task_get_current(void) {
  return 0;
}

TaskHandle_t pebble_task_get_handle_for_task(PebbleTask task) {
  return NULL;
}

const char* pebble_task_get_name(PebbleTask task) {
  return NULL;
}

void pebble_task_unregister(PebbleTask task) {
}

void pebble_task_create(PebbleTask pebble_task, TaskParameters_t *task_params,
                        TaskHandle_t *handle) {
}
