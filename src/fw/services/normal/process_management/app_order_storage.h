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

#include "process_management/app_install_manager.h"
#include "util/attributes.h"

typedef struct PACKED AppMenuOrderStorage {
  uint8_t list_length;
  AppInstallId id_list[];
} AppMenuOrderStorage;

void app_order_storage_init(void);

//! Returns an AppMenuOrderStorage struct on the kernel heap
AppMenuOrderStorage *app_order_read_order(void);

//! Writes a list of UUID's to the order file
void write_uuid_list_to_file(const Uuid *uuid_list, uint8_t count);
