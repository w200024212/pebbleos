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
#include <stdbool.h>

//! Turns every word after the first one into an initial.
//! e.g. Katharine Claire Berry -> Katharine C. B.
//! @param full_name String containing the full name
//! @param destination buffer to copy the abbreviated name into.
//! @param length Size of the destination buffer.
void phone_format_caller_name(const char *full_name, char *destination, size_t length);

//! Forces 2 line formatting on international phone numbers as well as
//! most long distance phone numbers (where required by format and length)
//! e.g. +55 408-555-1212 becomes
//! +55 408
//! 555-1212
//! @param phone_number String containing original phone number
//! @param destination buffer to copy the formatted phone number into.
//! @param length Size of the destination buffer.
void phone_format_phone_number(const char *phone_number, char *formatted_phone_number,
                               size_t length);
