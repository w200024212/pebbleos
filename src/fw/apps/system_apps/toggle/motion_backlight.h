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

#define MOTION_BACKLIGHT_TOGGLE_UUID {0xd4, 0xf7, 0xbe, 0x63, 0x97, 0xe6, 0x49, 0x52, \
                                      0xb2, 0x65, 0xdd, 0x4b, 0xce, 0x11, 0xc1, 0x55}

const PebbleProcessMd *motion_backlight_toggle_get_app_info(void);
