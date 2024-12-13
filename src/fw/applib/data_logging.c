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

#include "data_logging.h"
#include "services/normal/data_logging/dls_private.h"

#include "applib/app_logging.h"
#include "applib/applib_malloc.auto.h"
#include "syscall/syscall.h"

DataLoggingSessionRef data_logging_create(uint32_t tag, DataLoggingItemType item_type,
                                          uint16_t item_length, bool resume) {
  void *buffer = NULL;

  // For workers, dls_create_current_process() will create the buffer for us. All others must
  // allocate the buffer in their own heap (before going into privileged mode).
  if (pebble_task_get_current() != PebbleTask_Worker) {
    buffer = applib_malloc(DLS_SESSION_MIN_BUFFER_SIZE);
    if (!buffer) {
      APP_LOG(APP_LOG_LEVEL_ERROR, "insufficient memory");
      return NULL;
    }
  }

  // Create the session
  DataLoggingSessionRef session = sys_data_logging_create(tag, item_type, item_length, buffer,
                                                          resume);
  if (session == NULL && buffer != NULL) {
    applib_free(buffer);
  }

  return session;
}

void data_logging_finish(DataLoggingSessionRef logging_session) {
  sys_data_logging_finish(logging_session);
}

DataLoggingResult data_logging_log(DataLoggingSessionRef logging_session, const void *data,
                                   uint32_t num_items) {
  return sys_data_logging_log(logging_session, data, num_items);
}

