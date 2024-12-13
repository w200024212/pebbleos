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

//! Different types of objects that can be transferred over GetBytes
typedef enum {
  GetBytesObjectUnknown = 0x00,
  GetBytesObjectCoredump = 0x01,
  GetBytesObjectFile = 0x02,
  GetBytesObjectFlash = 0x03
} GetBytesObjectType;

// Possible values for GetBytesRspObjectInfo.error_code
typedef enum {
  GET_BYTES_OK = 0,
  GET_BYTES_MALFORMED_COMMAND = 1,
  GET_BYTES_ALREADY_IN_PROGRESS = 2,
  GET_BYTES_DOESNT_EXIST = 3,
  GET_BYTES_CORRUPTED = 4,
} GetBytesInfoErrorCode;
