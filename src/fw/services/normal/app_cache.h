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

#include "process_management/app_install_types.h"
#include "system/status_codes.h"

#include <stdbool.h>
#include <stdint.h>

//! @file app_cache.c
//! AppCache
//!
//! The AppCache keeps track of a cache of the applications that have binaries that reside on the
//! watch. When an app's binaries are removed from the watch, the entry with the same AppInstallId
//! is removed from the AppCache.
//!
//! When the app storage space has run out, a call to the app cache will retrieve the entry that
//! needs to be removed.

//! Initializes the AppCache
void app_cache_init(void);

//! Adds a blank entry with the given AppInstallId and total size to the AppCache
status_t app_cache_add_entry(AppInstallId app_id, uint32_t total_size);

//! Removes an entry with the given AppInstallId from the AppCache
status_t app_cache_remove_entry(AppInstallId app_id);

//! Checks whether an entry with the given AppInstallId is in the AppCache.
bool app_cache_entry_exists(AppInstallId app_id);

//! Increments data stored about an entry with the given AppInstallId in the AppCache
status_t app_cache_app_launched(AppInstallId app_id);

//! Ask the app cache to free up n bytes in case other parts of the system need room in the
//! filesystem
status_t app_cache_free_up_space(uint32_t bytes_needed);

//! Clears the entire AppCache
//! NOTE: Must be called from PebbleTask_KernelBackground
void app_cache_flush(void);
