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

#include <stddef.h>
#include <stdint.h>

//! An implementation of Consistent Overhead Byte Stuffing
//!
//! http://conferences.sigcomm.org/sigcomm/1997/papers/p062.pdf
//! http://en.wikipedia.org/wiki/Consistent_Overhead_Byte_Stuffing

//! Evaluates to the offset required when encoding in-place
#define COBS_OVERHEAD(n) (((n) + 253) / 254)
//! Evaluates to the maximum buffer size required to hold n bytes of data
//! after COBS encoding.
#define MAX_SIZE_AFTER_COBS_ENCODING(n) ((n) + COBS_OVERHEAD(n))

//! COBS-encode a buffer out to another buffer.
//!
//! @param [out] dst destination buffer. The buffer must be at least
//!                 MAX_SIZE_AFTER_COBS_ENCODING(length) bytes long.
//! @param [in] src source buffer
//! @param      length length of src
size_t cobs_encode(void * restrict dst, const void * restrict src,
                   size_t length);
