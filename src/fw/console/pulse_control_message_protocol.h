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

#include <util/net.h>

#include <stddef.h>
#include <stdint.h>

#define PULSE_CONTROL_MESSAGE_PROTOCOL (0x0001)

typedef const struct PulseControlMessageProtocol {
  void *(*send_begin_fn)(uint16_t app_protocol);
  void (*send_fn)(void *buf, size_t length);
} PulseControlMessageProtocol;

void pulse_control_message_protocol_on_packet(PulseControlMessageProtocol *this,
                                              void *information, size_t length);

void pulse_control_message_protocol_send_port_closed_message(
    PulseControlMessageProtocol *this, net16 port);
