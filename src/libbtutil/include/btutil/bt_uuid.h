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

#include <util/uuid.h>

#include <stdint.h>

//! Expands a 16-bit UUID to its 128-bit equivalent, using the Bluetooth base
//! UUID (0000xxxx-0000-1000-8000-00805F9B34FB).
//! @param uuid16 The 16-bit value from which to derive the 128-bit UUID.
//! @return Uuid structure containing the final UUID.
Uuid bt_uuid_expand_16bit(uint16_t uuid16);

//! Expands a 32-bit UUID to its 128-bit equivalent, using the Bluetooth base
//! UUID (xxxxxxxx-0000-1000-8000-00805F9B34FB).
//! @param uuid32 The 32-bit value from which to derive the 128-bit UUID.
//! @return Uuid structure containing the final UUID.
Uuid bt_uuid_expand_32bit(uint32_t uuid32);
