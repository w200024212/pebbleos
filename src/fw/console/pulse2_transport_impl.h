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

#include <stddef.h>
#include <stdint.h>

//! Get the max send size of the link.
size_t pulse_link_max_send_size(void);

//! Begin constructing a packet to send out the PULSE2 link.
//!
//! \param protocol encapsulation protocol number
void *pulse_link_send_begin(uint16_t protocol);

//! Send a packet out the PULSE2 link.
//! \param [out] buf buffer containing the packet data to send. Must be
//!        a buffer pointer returned by \ref pulse_link_send_begin.
//! \param length length of the packet in buf. Must not exceed the value
//!        returned by \ref pulse_link_max_send_size.
void pulse_link_send(void *buf, size_t length);

//! Release a transmit buffer without sending the packet.
//!
//! \param buf buffer to be released. Must be a buffer pointer returned
//!        by \ref pulse_link_send_begin.
void pulse_link_send_cancel(void *buf);


// Use preprocessor magic to generate function signatures for all protocol
// handler functions.
#define ON_PACKET(NUMBER, PACKET_HANDLER) \
  void PACKET_HANDLER(void *packet, size_t length);
#define ON_INIT(INITIALIZER) \
  void INITIALIZER(void);
#define ON_LINK_STATE_CHANGE(ON_UP, ON_DOWN) \
  void ON_UP(void); \
  void ON_DOWN(void);
#include "console/pulse2_transport_registry.def"
#undef ON_PACKET
#undef ON_INIT
#undef ON_LINK_STATE_CHANGE
