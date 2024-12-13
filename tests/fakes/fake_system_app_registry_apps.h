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

#include "process_management/pebble_process_md.h"

const PebbleProcessMd *simplicity_get_app_info(void);
const PebbleProcessMd *low_power_face_get_app_info(void);
const PebbleProcessMd *music_app_get_info(void);
const PebbleProcessMd *notifications_app_get_info(void);
const PebbleProcessMd *alarms_app_get_info(void);
const PebbleProcessMd *watchfaces_get_app_info(void);
const PebbleProcessMd *settings_get_app_info(void);
const PebbleProcessMd *recovery_first_use_app_get_app_info(void);
const PebbleProcessMd *set_time_get_app_info(void);
const PebbleProcessMd *quick_launch_setup_get_app_info(void);
const PebbleProcessMd *quiet_time_toggle_get_app_info(void);
