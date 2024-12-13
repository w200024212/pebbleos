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

#include "kernel/pebble_tasks.h"

bool task_watchdog_mask_get(PebbleTask task) {
  return true;
}

void task_watchdog_mask_set(PebbleTask task) {
}

void task_watchdog_mask_clear(PebbleTask task) {
}

void task_watchdog_feed(void) {
}

void task_watchdog_bit_set(PebbleTask task) {
}
