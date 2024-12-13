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

#include <bluetooth/pebble_bt.h>

#include <stddef.h>
#include <string.h>

void pebble_bt_uuid_expand(Uuid *uuid, uint32_t value) {
  static const uint8_t pebble_base_uuid_last_12_bytes[] = {
    0x32, 0x8E, 0x0F, 0xBB,
    0xC6, 0x42, 0x1A, 0xA6,
    0x69, 0x9B, 0xDA, 0xDA,
  };
  memcpy(&uuid->byte4, &pebble_base_uuid_last_12_bytes, sizeof(Uuid) - offsetof(Uuid, byte4));
  uuid->byte0 = (value >> 24) & 0xFF;
  uuid->byte1 = (value >> 16) & 0xFF;
  uuid->byte2 = (value >> 8) & 0xFF;
  uuid->byte3 = (value >> 0) & 0xFF;
}
