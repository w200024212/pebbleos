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

unsigned int base64_decode_inplace(char* buffer, unsigned int length);

// Encode a buffer as base 64
// @param out the encoded base64 string is written here
// @param out_len the size of the out buffer
// @param data the binary data to encode
// @param data_len the number of bytes of binary data
// @retval the number of characters required to encode all of the data, not including the
//         terminating null at the end. If this is less than the passed in out_len, then
//         NO characters will be written to the out buffer.
int32_t base64_encode(char *out, int out_len, const uint8_t *data, int32_t data_len);
