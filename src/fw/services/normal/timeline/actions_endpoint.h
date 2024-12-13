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

#include "attribute.h"
#include "item.h"

#include "services/common/comm_session/session.h"
#include "util/uuid.h"

#include <inttypes.h>
#include <stdlib.h>

//! Sends a request to the phone asking it to invoke an action
//! @param id UUID of the pin/notification
//! @param type Type of the pin/notification
//! @param action_id The id of the action that is being invoked
//! @param attributes The list of attributes
//! @param do_async True = perform send on KernelBG, False = perform send on current task
void timeline_action_endpoint_invoke_action(const Uuid *id, TimelineItemActionType type,
                                            uint8_t action_id, const AttributeList *attributes,
                                            bool do_async);

//! Handles messages from the phone sent to the timeline action endpoint
void timeline_action_endpoint_protocol_msg_callback(CommSession *session, const uint8_t* data,
                                                    size_t length);
