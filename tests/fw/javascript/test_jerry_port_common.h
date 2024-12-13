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

#include "jmem-heap.h"

static int s_app_heap_analytics_log_stats_to_app_heartbeat_call_count;
void app_heap_analytics_log_stats_to_app_heartbeat(bool is_rocky_app) {
  s_app_heap_analytics_log_stats_to_app_heartbeat_call_count++;
}

static int s_app_heap_analytics_log_rocky_heap_oom_fault_call_count;
void app_heap_analytics_log_rocky_heap_oom_fault(void) {
  s_app_heap_analytics_log_rocky_heap_oom_fault_call_count++;
}
