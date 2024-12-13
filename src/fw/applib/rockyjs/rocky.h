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

#include "jerry-api.h"
#include "resource/resource.h"

typedef union {
  uint8_t data[8];
  struct {
    char signature[4];
    uint8_t version;
    uint8_t padding[3];
  };
} RockySnapshotHeader;

#ifndef __clang__
_Static_assert(sizeof(RockySnapshotHeader) == 8, "RockyJS snapshot header size");
#endif

extern const RockySnapshotHeader ROCKY_EXPECTED_SNAPSHOT_HEADER;

bool rocky_add_global_function(char *name, jerry_external_handler_t handler);
bool rocky_add_function(jerry_value_t parent, char *name, jerry_external_handler_t handler);
jerry_value_t rocky_get_rocky_namespace(void);
jerry_value_t rocky_get_rocky_singleton(void);

bool rocky_event_loop_with_resource(uint32_t resource_id);

bool rocky_event_loop_with_system_resource(uint32_t resource_id);

bool rocky_event_loop_with_string_or_snapshot(const void *buffer, size_t buffer_size);

bool rocky_is_snapshot(const uint8_t *buffer, size_t buffer_size);
