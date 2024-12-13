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

#include "services/common/comm_session/session.h"
#include "util/attributes.h"

#include <stdint.h>

typedef enum {
  MetaResponseCodeNoError = 0x0,
  MetaResponseCodeCorruptedMessage = 0xd0,
  MetaResponseCodeDisallowed = 0xdd,
  MetaResponseCodeUnhandled = 0xdc,
} MetaResponseCode;

typedef struct MetaResponseInfo {
  CommSession *session;
  struct PACKED {
    //! @see MetaResponseCode
    uint8_t error_code;
    uint16_t endpoint_id;
  } payload;
} MetaResponseInfo;

//! Sends out a response for the "meta" endpoint, asynchronously on KernelBG.
//! @note The endpoint_id must be set in Little Endian byte order. This function will take care
//! of swapping it to the correct endianness.
void meta_endpoint_send_response_async(const MetaResponseInfo *meta_response_info);
