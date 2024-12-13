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

#include "kernel/events.h"
#include "services/normal/phone_call_util.h"

#include <stdbool.h>

void phone_ui_handle_incoming_call(PebblePhoneCaller *caller, bool can_answer,
                                   bool show_ongoing_call_ui, PhoneCallSource source);

void phone_ui_handle_outgoing_call(PebblePhoneCaller *caller);

void phone_ui_handle_missed_call(void);

void phone_ui_handle_call_start(bool can_decline);

void phone_ui_handle_call_end(bool call_accepted, bool disconnected);

void phone_ui_handle_call_hide(void);

void phone_ui_handle_caller_id(PebblePhoneCaller *caller);
