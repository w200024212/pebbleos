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

#include <stdbool.h>
#include <stdint.h>

//! Called by the QEMU serial driver whenever Pebble Protocol data is received.
void qemu_transport_handle_received_data(const uint8_t *data, uint32_t length);

//! Called by qemu version of comm_init() to tell ISPP that it is connected
void qemu_transport_set_connected(bool is_connected);

bool qemu_transport_is_connected(void);
