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

#include <pebble.h>

static void log_data(void *data) {
  DataLoggingSessionRef *session = data_logging_create(0, DATA_LOGGING_BYTE_ARRAY, 4, true);

  for (int i = 0; i < 32; ++i) {
    uint32_t t = ((uint32_t) time(NULL)) + i;
    data_logging_log(session, &t, 1);
  }

  data_logging_finish(session);

  app_timer_register(100, log_data, 0);
}

int main(void) {
  Window *window = window_create();

  const bool animated = true;
  window_stack_push(window, animated);

  app_timer_register(100, log_data, 0);

  app_event_loop();
}

