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
#include <stddef.h>

typedef struct Heap Heap;

//! Logs an analytics event about the native heap OOM fault.
void app_heap_analytics_log_native_heap_oom_fault(size_t requested_size, Heap *heap);

//! Logs an analytics event about the JerryScript heap OOM fault.
void app_heap_analytics_log_rocky_heap_oom_fault(void);

//! Captures native heap and given JerryScript heap stats to the app heartbeat.
//! @param jerry_mem_stats JerryScript heap stats on NULL if not available.
void app_heap_analytics_log_stats_to_app_heartbeat(bool is_rocky_app);
