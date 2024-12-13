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

#include <bluetooth/bluetooth_types.h>

#define GATT_CLIENT_DISCOVERY_MAX_RETRY_BITS (2)
#define GATT_CLIENT_DISCOVERY_MAX_RETRY ((1 << GATT_CLIENT_DISCOVERY_MAX_RETRY_BITS) - 1)

//! Starts discovery of all GATT services, characteristics and descriptors.
//! @param device The device of which its services, characteristics and
//! descriptors need to be discovered.
//! @return BTErrnoOK If the discovery process was started successfully,
//! BTErrnoInvalidParameter if the device was not connected,
//! BTErrnoInvalidState if service discovery was already on-going, or
//! an internal error otherwise (>= BTErrnoInternalErrorBegin).
BTErrno gatt_client_discovery_discover_all(const BTDeviceInternal *device);
