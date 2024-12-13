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

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct {
  size_t length;
  size_t bytes_written;
  uint8_t data[];
} Buffer;

//! Atomically add and return `length` bytes or add none and return 0
size_t buffer_add(Buffer* const buffer, const uint8_t* const data, const size_t length);

//! Remove `length` starting at `offset`.
//! The combination of length and offset must not exceed the written bytes.
size_t buffer_remove(Buffer* const b, const size_t offset, const size_t length);

//! Create buffer with a data region of size_bytes
Buffer* buffer_create(const size_t size_bytes);

//! Initializes Buffer with a given `length`.
//! Make sure that `buffer`'s data is can store `length` bytes.
void buffer_init(Buffer * const buffer, const size_t length);

//! Returns the number of remaining bytes that can be filled with `buffer_add`
size_t buffer_get_bytes_remaining(Buffer *b);

//! Empty buffer
void buffer_clear(Buffer * const buffer);

//! Return true if buffer is empty
bool buffer_is_empty(Buffer * const buffer);
