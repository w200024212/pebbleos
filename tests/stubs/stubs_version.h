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
#include "system/version.h"
#include "git_version.auto.h"

const FirmwareMetadata TINTIN_METADATA = {
  .version_timestamp = GIT_TIMESTAMP,
  .version_tag = GIT_TAG,
  .version_short = GIT_REVISION,
  .is_recovery_firmware = false,
  .hw_platform = FirmwareMetadataPlatformPebbleTwoPointZero,
  .metadata_version = FW_METADATA_CURRENT_STRUCT_VERSION,
};
