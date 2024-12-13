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

#include "drivers/rng.h"
#include "services/common/bluetooth/ble_root_keys.h"
#include "services/common/bluetooth/bluetooth_persistent_storage.h"
#include "system/hexdump.h"
#include "system/logging.h"

#include <bluetooth/sm_types.h>

static void prv_generate_root_keys(SM128BitKey *keys_out) {
  uint8_t *rand_buffer = (uint8_t *)keys_out;

  int tries_left = 20;
  // rng_rand generates only 4 bytes of random data at a time. Loop to fill up the whole array:
  for (uint32_t i = 0; i < ((sizeof(SM128BitKey) * SMRootKeyTypeNum) / sizeof(uint32_t)); ++i) {
    while (tries_left) {
      const bool success = rng_rand((uint32_t *) &rand_buffer[i * sizeof(uint32_t)]);
      if (success) {
        break;
      }
      --tries_left;
    }
  }
  if (tries_left == 0) {
    PBL_LOG(LOG_LEVEL_WARNING, "rng_rand() failed too many times, falling back to rand()");
    // Fall back to rand():
    for (uint32_t i = 0; i < (sizeof(SM128BitKey) * SMRootKeyTypeNum); ++i) {
      rand_buffer[i] = rand();
    }
  }
}

void ble_root_keys_get_and_generate_if_needed(SM128BitKey *keys_out) {
  SM128BitKey *enc_key = &keys_out[SMRootKeyTypeEncryption];
  SM128BitKey *id_key = &keys_out[SMRootKeyTypeIdentity];

  bool is_existing = false;
  if (bt_persistent_storage_get_root_key(SMRootKeyTypeIdentity, id_key) &&
      bt_persistent_storage_get_root_key(SMRootKeyTypeEncryption, enc_key)) {
    is_existing = true;
    goto finally;
  }

  prv_generate_root_keys(keys_out);

finally:
#ifndef RELEASE
  PBL_LOG(LOG_LEVEL_INFO, "BLE Root Keys (existing=%u):", is_existing);
  PBL_HEXDUMP(LOG_LEVEL_INFO, (const uint8_t *)keys_out, 2 * sizeof(SM128BitKey));
#endif
  if (!is_existing) {
    bt_persistent_storage_set_root_keys(keys_out);
  }
}
