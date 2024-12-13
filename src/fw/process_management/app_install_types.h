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

#include <stdint.h>
#include <stdbool.h>

//! ID unique to a given app for the duration that it is installed
//! System apps (system/resource) and banked applications are negative numbers.
//! AppDB flash apps are positive numbers
typedef int32_t AppInstallId;

#define INSTALL_ID_INVALID ((AppInstallId)0)

//! Returns true for system applications
bool app_install_id_from_system(AppInstallId id);

//! Returns true for user installed applications
bool app_install_id_from_app_db(AppInstallId id);
