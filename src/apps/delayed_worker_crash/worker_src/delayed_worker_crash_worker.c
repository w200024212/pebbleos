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

#include <pebble_worker.h>

#define WORKER_CRASH_DELAY_MS 5000

static void worker_timer_callback(void *data) {
  // Free -1 to crash the worker
  free((void *) -1);
}

static void worker_init(void) {
  app_timer_register(WORKER_CRASH_DELAY_MS, worker_timer_callback, NULL);
}

int main(void) {
  worker_init();
  worker_event_loop();
}
