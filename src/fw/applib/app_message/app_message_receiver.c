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

#include "applib/app_message/app_message_receiver.h"
#include "applib/app_message/app_message_internal.h"
#include "applib/app_inbox.h"
#include "process_state/app_state/app_state.h"
#include "system/logging.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// All these functions execute on App Task

void app_message_receiver_message_handler(const uint8_t *data, size_t length,
                                          AppInboxConsumerInfo *consumer_info) {
  AppMessageReceiverHeader *message = (AppMessageReceiverHeader *)data;
  app_message_app_protocol_msg_callback(message->session, message->data,
                                        length - sizeof(AppMessageReceiverHeader), consumer_info);
}

void app_message_receiver_dropped_handler(uint32_t num_dropped_messages) {
  app_message_inbox_handle_dropped_messages(num_dropped_messages);
}

bool app_message_receiver_open(size_t buffer_size) {
  AppInbox **app_message_inbox = app_state_get_app_message_inbox();
  if (*app_message_inbox) {
    PBL_LOG(LOG_LEVEL_INFO, "App PP receiver already open, not opening again");
    return true;
  }

  // Make sure that at least one message of `buffer_size` will fit, by adding the header size:
  // Allocate overhead for 1 (N)ACK + 1 Push message:
  static const uint32_t min_num_messages = 2;
  size_t final_buffer_size =
    (sizeof(AppMessageReceiverHeader) * min_num_messages) + buffer_size + sizeof(AppMessageAck);
  AppInbox *inbox = app_inbox_create_and_register(final_buffer_size, min_num_messages,
                                                  app_message_receiver_message_handler,
                                                  app_message_receiver_dropped_handler);
  if (!inbox) {
    // No logging needed, the inner calls log themselves already
    return false;
  }

  *app_message_inbox = inbox;
  return true;
}

void app_message_receiver_close(void) {
  AppInbox **inbox = app_state_get_app_message_inbox();
  if (!(*inbox)) {
    PBL_LOG(LOG_LEVEL_INFO, "App PP receiver already closed");
    return;
  }

  app_inbox_destroy_and_deregister(*inbox);
  *inbox = NULL;
}
