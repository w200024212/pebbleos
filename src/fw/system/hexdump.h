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

#include "util/hexdump.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void hexdump_log(int level, const uint8_t *data, size_t length);
void hexdump_log_src(const char *src_filename, int src_line_number, int level,
                     const uint8_t *data, size_t length, HexdumpLineCallback cb);

void hexdump_using_serial(int level, const char *src_filename, int src_line_number,
                         const char *line_buffer);
void hexdump_using_prompt(int level, const char *src_filename, int src_line_number,
                         const char *line_buffer);
void hexdump_using_pbllog(int level, const char *src_filename, int src_line_number,
                         const char *line_buffer);

#ifdef PBL_LOG_ENABLED
#define PBL_HEXDUMP_D_SERIAL(level, data, length)        \
  hexdump_log_src(__FILE_NAME__, __LINE__, level, data, length, hexdump_using_serial)
#define PBL_HEXDUMP_D_PROMPT(level, data, length)        \
  hexdump_log_src(__FILE_NAME__, __LINE__, level, data, length, hexdump_using_prompt)
#define PBL_HEXDUMP_D(domain, level, data, length)                      \
  if (domain) hexdump_log_src(__FILE_NAME__, __LINE__, level, data, length, hexdump_using_pbllog)
#define PBL_HEXDUMP(level, data, length) \
  hexdump_log_src(__FILE_NAME__, __LINE__, level, data, length, hexdump_using_pbllog);
#else
#define PBL_HEXDUMP_D_SERIAL(level, data, length)
#define PBL_HEXDUMP_D(domain, level, data, length)
#define PBL_HEXDUMP(level, data, length)
#define PBL_HEXDUMP_D_PROMPT(level, data, length)
#endif
