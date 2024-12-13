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
#include <stdio.h>

void prompt_command_continues_after_returning(void) {
}

void prompt_command_finish(void) {
}

void prompt_send_response(const char* response) {
  printf("%s\n", response);
}

void prompt_send_response_fmt(char* buffer, size_t buffer_size, const char* fmt, ...) {
  va_list fmt_args;
  va_start(fmt_args, fmt);
  vprintf(fmt, fmt_args);
  va_end(fmt_args);
  printf("\n");
}
