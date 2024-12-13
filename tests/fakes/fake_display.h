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

#define DISP_BYTES_LINE DISP_COLS / 8
// Bytes_per_line + 1 byte for the line address + 1 byte for a null trailer + 1 optional byte for a write command
#define DISP_DMA_BUFFER_SIZE (DISP_BYTES_LINE + 3)

typedef struct {
  uint8_t address;
  uint8_t* data;
} DisplayRow;

typedef bool(*NextRowCallback)(DisplayRow* row);
typedef void(*UpdateCompleteCallback)(void);

typedef enum {
  DISPLAY_STATE_IDLE,
  DISPLAY_STATE_WRITING
} DisplayState;

typedef struct {
  DisplayState state;
  NextRowCallback get_next_row;
  UpdateCompleteCallback complete;
} DisplayContext;


void display_init(void);

void display_clear(void);

void display_update(NextRowCallback nrcb, UpdateCompleteCallback uccb);

void display_enter_static(void);

void display_pulse_vcom(void);
