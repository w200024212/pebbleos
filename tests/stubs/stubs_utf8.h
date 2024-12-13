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

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint8_t utf8_t;

uint32_t utf8_peek_codepoint(utf8_t *string, utf8_t **next_ptr) {
  return 0;
}

size_t utf8_copy_character(utf8_t *dest, utf8_t *origin, size_t length) {
  return 0;
}
