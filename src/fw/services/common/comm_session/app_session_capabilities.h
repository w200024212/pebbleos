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

#include "services/common/comm_session/session.h"
#include "util/uuid.h"

//! @param capability The capability to check for.
//! @returns True if the session for the current application supports the capability of interest.
//! If the session is currently not connected, it will use cached data. If no cache exists
//! and the session is not connected, false will be returned.
bool comm_session_current_app_session_cache_has_capability(CommSessionCapability capability);

//! Removes the cached app session capabilities for app with specified uuid.
void comm_session_app_session_capabilities_evict(const Uuid *app_uuid);

void comm_session_app_session_capabilities_init(void);
