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

#include "util/mbuf.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

//! NOTE: MBufIterator APIs are not thread safe

typedef struct {
  MBuf *m;
  uint32_t data_index;
} MBufIterator;

//! Initializes an MBufIterator
void mbuf_iterator_init(MBufIterator *iter, MBuf *m);

//! Check if there is no data left in the MBuf chain
bool mbuf_iterator_is_finished(MBufIterator *iter);

//! Reads the next byte of data in the MBuf chain
bool mbuf_iterator_read_byte(MBufIterator *iter, uint8_t *data);

//! Writes the next byte of data in the MBuf chain
bool mbuf_iterator_write_byte(MBufIterator *iter, uint8_t data);

//! Gets the MBuf which the next byte of data is in
MBuf *mbuf_iterator_get_current_mbuf(MBufIterator *iter);
