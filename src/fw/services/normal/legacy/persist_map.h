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

#include "util/uuid.h"
#include "system/status_codes.h"

/* persist_map is an intermediate mapping until app install ids are reimplemented.
 * This is an id, uuid record based solution with the id as a positive native int.
 */

int persist_map_get_size();

int persist_map_add_uuid(const Uuid *uuid);

int persist_map_get_id(const Uuid *uuid);

int persist_map_auto_id(const Uuid *uuid);

int persist_map_get_uuid(int id, Uuid *uuid);

status_t persist_map_init();

//! Dump the persist map to LOG_LEVEL_INFO
void persist_map_dump(void);
