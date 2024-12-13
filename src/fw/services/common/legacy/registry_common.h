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

#include "util/attributes.h"

#define MAX_KEY_SIZE_BYTES 16
#define MAX_VALUE_SIZE_BYTES 44
#define UUID_SIZE_BYTES 5

typedef struct PACKED {
  bool active;
  uint8_t key_length;
  uint8_t description;
  uint8_t value_length;
  uint8_t uuid[UUID_SIZE_BYTES];
  char key[MAX_KEY_SIZE_BYTES];
  uint8_t value[MAX_VALUE_SIZE_BYTES];
} Record;

static const uint8_t REGISTRY_SYSTEM_UUID[UUID_SIZE_BYTES] = {
    0x00, 0x00, 0x00, 0x00, 0x00
};
