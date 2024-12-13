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

#include "protobuf_log.h"

#include "services/common/hrm/hrm_manager.h"
#include "services/normal/activity/activity.h"

#include <stdbool.h>
#include <stdint.h>

ProtobufLogRef protobuf_log_activity_sessions_create(void);

bool protobuf_log_activity_sessions_add(ProtobufLogRef ref, time_t sample_utc,
                                       ActivitySession *session);

bool protobuf_log_activity_sessions_decode(pebble_pipeline_Event *event_in,
                                           ActivitySession *session_out);
