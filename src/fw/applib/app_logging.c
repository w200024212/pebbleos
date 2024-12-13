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

#include "applib/app_logging.h"

#include <stdint.h>
#include <stddef.h>

// FIXME PBL-1629: move needed declarations into applib
#include "syscall/syscall.h"
#include "process_management/app_manager.h"
#include "services/common/comm_session/session.h"
#include "system/logging.h"
#include "system/passert.h"

void app_log_vargs(uint8_t log_level, const char* src_filename, int src_line_number, const char* fmt, va_list args) {
  char log_buffer[LOG_BUFFER_LENGTH];
  _Static_assert(sizeof(log_buffer) > sizeof(AppLogBinaryMessage), "log_buffer too small for AppLogBinaryMessage");

  AppLogBinaryMessage* msg = (AppLogBinaryMessage*)log_buffer;
  sys_get_app_uuid(&msg->uuid);
  const size_t log_msg_offset = offsetof(AppLogBinaryMessage, log_msg);
  int bin_msg_length = pbl_log_binary_format((char*)&msg->log_msg, sizeof(log_buffer) - log_msg_offset, log_level,
                                             src_filename, src_line_number, fmt, args);
  sys_app_log(log_msg_offset + bin_msg_length, log_buffer);
}

void app_log(uint8_t log_level, const char* src_filename, int src_line_number, const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  app_log_vargs(log_level, src_filename, src_line_number, fmt, args);
  va_end(args);
}

