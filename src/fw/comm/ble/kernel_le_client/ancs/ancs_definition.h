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

#include "ancs.h"

//! ANCS Service UUID
static const Uuid s_ancs_service_uuid = {
  0x79, 0x05, 0xf4, 0x31, 0xb5, 0xce, 0x4e, 0x99,
  0xa4, 0x0f, 0x4b, 0x1e, 0x12, 0x2d, 0x00, 0xd0
};

//! ANCS Characteristic UUIDs
static const Uuid s_ancs_characteristic_uuids[NumANCSCharacteristic] = {
  [ANCSCharacteristicNotification] = {
    0x9f, 0xbf, 0x12, 0x0d, 0x63, 0x01, 0x42, 0xd9,
    0x8c, 0x58, 0x25, 0xe6, 0x99, 0xa2, 0x1d, 0xbd
  },
  [ANCSCharacteristicData] = {
    0x22, 0xea, 0xc6, 0xe9, 0x24, 0xd6, 0x4b, 0xb5,
    0xbe, 0x44, 0xb3, 0x6a, 0xce, 0x7c, 0x7b, 0xfb
  },
  [ANCSCharacteristicControl] = {
    0x69, 0xd1, 0xd8, 0xf3, 0x45, 0xe1, 0x49, 0xa8,
    0x98, 0x21, 0x9b, 0xbd, 0xfd, 0xaa, 0xd9, 0xd9
  },
};
