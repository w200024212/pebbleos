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

#include "services/common/analytics/analytics.h"
#include "services/common/analytics/analytics_event.h"

//! Stub for PRF

void sys_analytics_set(AnalyticsMetric metric, uint64_t value, AnalyticsClient client) {
}

void sys_analytics_add(AnalyticsMetric metric, uint64_t increment, AnalyticsClient client) {
}

void sys_analytics_inc(AnalyticsMetric metric, AnalyticsClient client) {
}

void sys_analytics_max(AnalyticsMetric metric, int64_t val, AnalyticsClient client) {
}

void sys_analytics_logging_log_event(AnalyticsEventBlob *event_blob) {
}
