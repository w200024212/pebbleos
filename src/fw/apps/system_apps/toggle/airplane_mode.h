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

#define AIRPLANE_MODE_TOGGLE_UUID {0x88, 0xc2, 0x8c, 0x12, 0x7f, 0x81, 0x42, 0xdb, \
                                   0xaa, 0xa6, 0x14, 0xcc, 0xef, 0x6f, 0x27, 0xe5}

const PebbleProcessMd *airplane_mode_toggle_get_app_info(void);
