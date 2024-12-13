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

#include "system/hexdump.h"
#include "system/logging.h"
#include "util/hexdump.h"
#include "console/prompt.h"

void hexdump_log(int level, const uint8_t *data, size_t length) {
  PBL_HEXDUMP_D(LOG_DOMAIN_MISC, level, data, length);
}

void hexdump_using_serial(int level, const char *src_filename, int src_line_number,
                          const char *line_buffer) {
  dbgserial_putstr(line_buffer);
}

void hexdump_using_prompt(int level, const char *src_filename, int src_line_number,
                          const char *line_buffer) {
  prompt_send_response(line_buffer);
}

void hexdump_using_pbllog(int level, const char *src_filename, int src_line_number,
                          const char *line_buffer) {
  pbl_log_sync(level, src_filename, src_line_number, "%s", line_buffer);
}

void hexdump_log_src(const char *src_filename, int src_line_number, int level,
                     const uint8_t *data, size_t length, HexdumpLineCallback cb) {
  hexdump(src_filename, src_line_number, level, data, length, cb);
}
