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

#include "applib/app_smartstrap.h"
#include "services/normal/accessory/smartstrap_connection.h"
#include "services/normal/accessory/smartstrap_profiles.h"

#include <stdint.h>

//! Sends a connection request to the smartstrap (should only be called from smartstrap_connection)
void smartstrap_link_control_connect(void);

//! Disconnects from the smartstrap
void smartstrap_link_control_disconnect(void);

//! Checks whether the specified profile is supported by the smartstrap which is connected.
bool smartstrap_link_control_is_profile_supported(SmartstrapProfile profile);
