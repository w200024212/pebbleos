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

#include "analytics_event.h"

typedef enum {
  ANALYTICS_BLOB_KIND_DEVICE_HEARTBEAT,
  ANALYTICS_BLOB_KIND_APP_HEARTBEAT,
  ANALYTICS_BLOB_KIND_EVENT
} AnalyticsBlobKind;

void analytics_logging_init(void);

//! Used internally to log raw analytics events
void analytics_logging_log_event(AnalyticsEventBlob *event_blob);

//! Exposed for unit testing only
void analytics_logging_system_task_cb(void *ignored);
