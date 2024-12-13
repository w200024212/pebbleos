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

Version process_metadata_get_sdk_version(const PebbleProcessMd *md) {
  return (Version) { PROCESS_INFO_CURRENT_SDK_VERSION_MAJOR, PROCESS_INFO_CURRENT_SDK_VERSION_MINOR };
}

ProcessAppSDKType process_metadata_get_app_sdk_type(const PebbleProcessMd *md) {
  return 0;
}

int process_metadata_get_code_bank_num(const PebbleProcessMd *md) {
  return 0;
}
