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

#include "rocky_api.h"
#include "jerry-api.h"

// array of evented APIs, last entry must be NULL
void rocky_global_init(const RockyGlobalAPI *const *evented_apis);

void rocky_global_deinit(void);

bool rocky_global_has_event_handlers(const char *event_name);

void rocky_global_call_event_handlers(jerry_value_t event);

//! Schedules the event to be processed on a later event loop iteration.
void rocky_global_call_event_handlers_async(jerry_value_t event);

// Create a BaseEvent, filling in the type field with the given type string.
// The returned event must be released by the caller.
jerry_value_t rocky_global_create_event(const char *type_str);
