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

#if PULSE_EVERYWHERE

#include "pulse_control_message_protocol.h"

#include <util/attributes.h>

#include <stdint.h>
#include <string.h>

typedef struct PACKED PCMPPacket {
  uint8_t code;
  char information[];
} PCMPPacket;

enum PCMPCode {
  PCMPCode_EchoRequest = 1,
  PCMPCode_EchoReply = 2,
  PCMPCode_DiscardRequest = 3,

  PCMPCode_PortClosed = 129,
  PCMPCode_UnknownCode = 130,
};

void pulse_control_message_protocol_on_packet(
    PulseControlMessageProtocol *this, void *raw_packet, size_t packet_length) {
  if (packet_length < sizeof(PCMPPacket)) {
    // Malformed packet; silently discard.
    return;
  }

  PCMPPacket *packet = raw_packet;
  switch (packet->code) {
    case PCMPCode_EchoRequest: {
      PCMPPacket *reply = this->send_begin_fn(PULSE_CONTROL_MESSAGE_PROTOCOL);
      memcpy(reply, packet, packet_length);
      reply->code = PCMPCode_EchoReply;
      this->send_fn(reply, packet_length);
      break;
    }

    case PCMPCode_EchoReply:
    case PCMPCode_DiscardRequest:
    case PCMPCode_PortClosed:
    case PCMPCode_UnknownCode:
      break;

    default: {
      PCMPPacket *reply = this->send_begin_fn(PULSE_CONTROL_MESSAGE_PROTOCOL);
      reply->code = PCMPCode_UnknownCode;
      memcpy(reply->information, &packet->code, sizeof(packet->code));
      this->send_fn(reply, sizeof(PCMPPacket) + sizeof(packet->code));
      break;
    }
  }
}

void pulse_control_message_protocol_send_port_closed_message(
    PulseControlMessageProtocol *this, net16 port) {
  PCMPPacket *message = this->send_begin_fn(PULSE_CONTROL_MESSAGE_PROTOCOL);
  message->code = PCMPCode_PortClosed;
  memcpy(message->information, &port, sizeof(port));
  this->send_fn(message, sizeof(PCMPPacket) + sizeof(port));
}

#endif
