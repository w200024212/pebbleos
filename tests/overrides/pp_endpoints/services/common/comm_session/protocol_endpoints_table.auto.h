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

// GENERATED -- DO NOT EDIT

#include "test_endpoint_ids.h"

extern void private_test_protocol_msg_callback(CommSession *session,
                                               const uint8_t* data, size_t length);
extern void public_test_protocol_msg_callback(CommSession *session,
                                              const uint8_t* data, size_t length);
extern void any_test_protocol_msg_callback(CommSession *session,
                                           const uint8_t* data, size_t length);

extern ReceiverImplementation g_system_test_receiver_imp;

static const PebbleProtocolEndpoint s_protocol_endpoints[] = {
  { PRIVATE_TEST_ENDPOINT_ID, private_test_protocol_msg_callback,
    PebbleProtocolAccessPrivate, &g_system_test_receiver_imp },
  { PUBLIC_TEST_ENDPOINT_ID, public_test_protocol_msg_callback,
    PebbleProtocolAccessPublic, &g_system_test_receiver_imp },
  { ANY_TEST_ENDPOINT_ID, any_test_protocol_msg_callback,
    PebbleProtocolAccessAny, &g_system_test_receiver_imp },
};

