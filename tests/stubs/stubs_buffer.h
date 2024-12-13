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

size_t buffer_get_bytes_remaining(Buffer *b) {
  return 0;
}

size_t buffer_add(Buffer* const b, const uint8_t* const data, const size_t length) {
  return 0;
}

size_t buffer_remove(Buffer* const b, const size_t offset, const size_t length) {
  return 0;
}

Buffer* buffer_create(const size_t size_bytes) {
  return NULL;
}

void buffer_init(Buffer * const buffer, const size_t length) {
}

void buffer_clear(Buffer * const buffer) {
}

bool buffer_is_empty(Buffer * const buffer) {
  return true;
}
