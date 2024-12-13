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

//! Currently this file serves as a cache for the existence of the SEND_TEXT_NOTIF_PREF_KEY, and
//! a reply action within that key.
//! This is required because a user can have a supported mobile app but not a supported carrier,
//! and in that case we don't want to show the app in the launcher.
//! We cache the existence of this key so that the launcher isn't slowed down by flash reads

void send_text_service_init(void);

bool send_text_service_is_send_text_supported(void);
