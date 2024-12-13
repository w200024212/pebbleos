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
#include <stdbool.h>

/*
 * Calculate an 8-bit CRC of a given byte sequence. Note that this is not using the standard CRC-8
 * polynomial, because the standard polynomial isn't very good. If the big_endian flag is set, the
 * crc will be calculated by going through the data in reverse order (high->low index).
 */
uint8_t crc8_calculate_bytes(const uint8_t *data, uint32_t data_length, bool big_endian);
void crc8_calculate_bytes_streaming(const uint8_t *data, uint32_t data_length, uint8_t *crc,
                                    bool big_endian);
