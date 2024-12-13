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

#include "ancs_types.h"

//! Initialize app name storage and allocate cache
void ancs_app_name_storage_init(void);

//! Deinitialize app name storage and free cache
void ancs_app_name_storage_deinit(void);

//! Store an app name/app id pair in the app name cache
//! @param app_id the app ID attribute to use as key
//! @param app_name the app name attribute to store
//! @note will evict the oldest entry if the cache is full
void ancs_app_name_storage_store(const ANCSAttribute *app_id, const ANCSAttribute *app_name);

//! Retrieve an app name from storage.
//! @param app_id the app ID attribute used as key
//! @return an ANCSAttribute containing the name of the app, NULL if not found.
//! @note This returns a pointer to the data in the cache. If the cache gets invalidated
//! the pointer will no longer be valid. Copy the data somewhere if you want to keep it
//! around for a while.
ANCSAttribute *ancs_app_name_storage_get(const ANCSAttribute *app_id);
