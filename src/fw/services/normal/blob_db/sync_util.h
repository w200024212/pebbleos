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

#include "services/normal/blob_db/api.h"
#include "services/normal/settings/settings_file.h"

// Caution: CommonTimelineItemHeader .flags & .status are stored inverted and not auto-restored
// by the underlying db API. If .flags or .status is used from a CommonTimelineItemHeader below,
// be very careful.

//! A settings file each callback which checks if the there are dirty records in the file
//! @param context The address of a bool which will get set
bool sync_util_is_dirty_cb(SettingsFile *file, SettingsRecordInfo *info, void *context);

//! A settings file each callback which builds a BlobDBDirtyItem list
//! @param context The address of an empty dirty list which will get built
bool sync_util_build_dirty_list_cb(SettingsFile *file, SettingsRecordInfo *info, void *context);
