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

#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

ProtobufLogRef protobuf_log_hr_create(ProtobufLogTransportCB transport);

bool protobuf_log_hr_add_sample(ProtobufLogRef ref, time_t sample_utc, uint8_t bpm,
                                HRMQuality quality);
