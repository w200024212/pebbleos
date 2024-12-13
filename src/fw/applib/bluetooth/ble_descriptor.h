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

//! Gets the UUID for a descriptor.
//! @param descriptor The descriptor for which to get the UUID.
//! @return The UUID of the descriptor
Uuid ble_descriptor_get_uuid(BLEDescriptor descriptor);

//! Gets the characteristic for a descriptor.
//! @param descriptor The descriptor for which to get the characteristic.
//! @return The characteristic
//! @note For convenience, the services are owned by the system and references
//! to services, characteristics and descriptors are guaranteed to remain valid
//! *until the BLEClientServiceChangeHandler is called again* or until
//! application is terminated.
BLECharacteristic ble_descriptor_get_characteristic(BLEDescriptor descriptor);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// (FUTURE / LATER / NOT SCOPED)
// Just to see how symmetric the Server APIs would be:


BLEDescriptor ble_descriptor_create(const Uuid *uuid,
                                    BLEAttributeProperty properties);

BTErrno ble_descriptor_destroy(BLEDescriptor descriptor);
