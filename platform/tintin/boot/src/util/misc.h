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

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#define MHZ_TO_HZ(hz) (((uint32_t)(hz)) * 1000000)

#define ARRAY_LENGTH(array) (sizeof((array))/sizeof((array)[0]))

//! Find the log base two of a number rounded up
int ceil_log_two(uint32_t n);

//! Convert num to a hex string and put in buffer
void itoa(uint32_t num, char *buffer, int buffer_length);
