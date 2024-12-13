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

#include "process_management/app_manager.h"

#define QUIET_TIME_TOGGLE_UUID {0x22, 0x20, 0xd8, 0x05, 0xcf, 0x9a, 0x4e, 0x12, \
                                0x92, 0xb9, 0x5c, 0xa7, 0x78, 0xaf, 0xf6, 0xbb}

const PebbleProcessMd *quiet_time_toggle_get_app_info(void);
