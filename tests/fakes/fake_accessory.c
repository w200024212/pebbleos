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

#include "fake_accessory.h"

#include "clar_asserts.h"

#include "services/normal/accessory/smartstrap_comms.h"

#include <string.h>

#define BUFFER_LENGTH 200

static uint8_t s_buffer[BUFFER_LENGTH];
static int s_buffer_index = 0;
static bool s_did_send_byte = false;

void accessory_disable_input(void) {
}

void accessory_enable_input(void) {
}

void accessory_use_dma(bool use_dma) {
}

void accessory_send_byte(uint8_t data) {
  cl_assert(s_buffer_index < BUFFER_LENGTH);
  s_buffer[s_buffer_index++] = data;
  s_did_send_byte = true;
}

void accessory_send_stream(AccessoryDataStreamCallback callback, void *context) {
  s_buffer_index = 0;
  memset(s_buffer, 0, BUFFER_LENGTH);
  while (callback(context)) {
    cl_assert(s_did_send_byte);
  }
}

void fake_accessory_get_buffer(uint8_t **buffer, int *length) {
  *buffer = s_buffer;
  *length = s_buffer_index;
}
