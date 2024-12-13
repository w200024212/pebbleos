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

#include "analytics.h"
#include "kernel/pebble_tasks.h"
#include "analytics_heartbeat.h"

typedef struct {
  ListNode node;
  AnalyticsHeartbeat *heartbeat;
} AnalyticsHeartbeatList;

typedef void (*AnalyticsHeartbeatCallback)(AnalyticsHeartbeat *heartbeat, void *data);

void analytics_storage_init(void);

void analytics_storage_take_lock(void);
bool analytics_storage_has_lock(void);
void analytics_storage_give_lock(void);

// Must hold the lock before using any of the functions below this marker.
AnalyticsHeartbeat *analytics_storage_hijack_device_heartbeat();
AnalyticsHeartbeatList *analytics_storage_hijack_app_heartbeats();

AnalyticsHeartbeat *analytics_storage_find(AnalyticsMetric metric, const Uuid *uuid,
                                           AnalyticsClient client);

const Uuid *analytics_uuid_for_client(AnalyticsClient client);
