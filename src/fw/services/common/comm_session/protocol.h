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

#include <util/attributes.h>
#include <stdint.h>

typedef struct PACKED {
  uint16_t length;
  uint16_t endpoint_id;
} PebbleProtocolHeader;

#define COMM_PRIVATE_MAX_INBOUND_PAYLOAD_SIZE 2044
#define COMM_PUBLIC_MAX_INBOUND_PAYLOAD_SIZE 144
// TODO: If we have memory to spare, let's crank this up to improve data spooling
#define COMM_MAX_OUTBOUND_PAYLOAD_SIZE 656
