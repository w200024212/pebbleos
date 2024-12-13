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

typedef const struct PPPControlProtocol PPPControlProtocol;

typedef enum PPPCPCloseWait {
  PPPCPCloseWait_NoWait,
  PPPCPCloseWait_WaitForClosed
} PPPCPCloseWait;

//! Notify the control protocol that the lower layer is ready to carry traffic.
void ppp_control_protocol_lower_layer_is_up(PPPControlProtocol *protocol);

//! Notify the control protocol that the lower layer is no longer ready
//! to carry traffic.
void ppp_control_protocol_lower_layer_is_down(PPPControlProtocol *protocol);

//! Notify the control protocol that the layer is administratively available
//! for carrying traffic.
void ppp_control_protocol_open(PPPControlProtocol *protocol);

//! Notify the control protocol that the layer is not allowed to be opened.
void ppp_control_protocol_close(PPPControlProtocol *protocol,
                                PPPCPCloseWait wait);

//! Pass an incoming packet to the control protocol.
void ppp_control_protocol_handle_incoming_packet(PPPControlProtocol *protocol,
                                                 void *packet, size_t length);
