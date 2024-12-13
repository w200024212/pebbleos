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

#include "console/dbgserial.h"
#include "system/logging.h"
#include "system/passert.h"

#include "util/assert.h"
#include "util/logging.h"

void util_log(const char *filename, int line, const char *string) {
  pbl_log(LOG_LEVEL_INFO, filename, line, string);
}

void util_dbgserial_str(const char *string) {
  dbgserial_putstr(string);
}

NORETURN util_assertion_failed(const char *filename, int line) {
  passert_failed_no_message(filename, line);
}
