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

void pulse_logging_init(void);

//! Log a message using PULSEv2
void pulse_logging_log(uint8_t log_level, const char* src_filename,
                       uint16_t src_line_number, const char* message);

//! Log a message using PULSEv2 synchronously, even from a critical section
void pulse_logging_log_sync(
    uint8_t log_level, const char* src_filename,
    uint16_t src_line_number, const char* message);

//! Log a message from a fault handler by concatenating several strings.
void *pulse_logging_log_sync_begin(
    uint8_t log_level, const char *src_filename, uint16_t src_line_number);
void pulse_logging_log_sync_append(void *ctx, const char *message);
void pulse_logging_log_sync_send(void *ctx);

//! Flush the ISR log buffer. Call this when crashing.
void pulse_logging_log_buffer_flush(void);
