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

#include "services/common/legacy/registry_common.h"

#include <stdbool.h>
#include <stdint.h>


typedef struct {
  unsigned int address;
  unsigned int begin;
  unsigned int end;
} RegistryCursor;

#define FLASH_CURSOR_UNINITIALIZED  (~0)
#define REGISTRY_HEADER_SIZE_BYTES 3

typedef struct {
  bool is_different_from_flash;
  Record* records;
  int num_records;
  unsigned int registry_size_bytes;
  //! Size of the buffer in bytes when registry is written to flash
  unsigned int total_buffer_size_bytes;
  RegistryCursor* cursor;
} Registry;


void registry_private_init(Registry* registry);

void registry_private_read_from_flash(Registry* registry);

void registry_private_write_to_flash(Registry* registry);

Record* registry_private_get(const char* key, const uint8_t key_length, const uint8_t* uuid,
                             Registry* registry);

int registry_private_add(const char* key, const uint8_t key_length, const uint8_t* uuid,
                         uint8_t description, const uint8_t* value, uint8_t value_length,
                         Registry* registry);

void registry_private_remove_all(const uint8_t* uuid, Registry* registry);

int registry_private_remove(const char* key, const uint8_t key_length, const uint8_t* uuid,
                            Registry* registry);

