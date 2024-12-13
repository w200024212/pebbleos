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

#include "services/normal/accessory/smartstrap_comms.h"

#include <stdbool.h>
#include <stdint.h>

void smartstrap_profiles_handle_read(bool success, SmartstrapProfile profile, uint32_t length);

void fake_smartstrap_profiles_check_read_params(bool success, SmartstrapProfile profile,
                                                uint32_t length);

void smartstrap_profiles_handle_notification(bool success, SmartstrapProfile profile);

void fake_smartstrap_profiles_check_notify_params(bool success, SmartstrapProfile profile);

SmartstrapResult smartstrap_profiles_handle_request(const SmartstrapRequest *request);

void smartstrap_profiles_handle_read_aborted(SmartstrapProfile profile);

void fake_smartstrap_profiles_check_request_params(const SmartstrapRequest *request);
