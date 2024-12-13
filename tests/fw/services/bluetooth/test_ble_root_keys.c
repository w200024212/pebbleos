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

#include "services/common/bluetooth/ble_root_keys.h"

#include "clar.h"
#include <string.h>

/// Stubs

#include "stubs_hexdump.h"
#include "stubs_logging.h"

static const SM128BitKey s_retrieved_keys[SMRootKeyTypeNum] = {
  [SMRootKeyTypeEncryption] = {
    0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee,
    0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee,
  },
  [SMRootKeyTypeIdentity] = {
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
  },
};

bool bt_persistent_storage_get_root_key(SMRootKeyType key_type, SM128BitKey *key_out) {
  cl_assert(key_type < SMRootKeyTypeNum);
  bool rv = cl_mock_type(bool);
  if (rv) {
    memcpy(key_out, &s_retrieved_keys[key_type], sizeof(*key_out));
  }
  return rv;
}

static SM128BitKey s_stored_keys[SMRootKeyTypeNum];
void bt_persistent_storage_set_root_keys(SM128BitKey *keys_in) {
  cl_mock_type(void);
  memcpy(s_stored_keys, keys_in, sizeof(SM128BitKey) * SMRootKeyTypeNum);
}

static uint32_t s_rng_output;
#define RNG_ROUNDS (sizeof(SM128BitKey) / sizeof(uint32_t))
#define RNG_MAX_RETRIES (20)

bool rng_rand(uint32_t *rand_out) {
  bool rv = cl_mock_type(bool);
  if (rv) {
    *rand_out = s_rng_output;
    ++s_rng_output;
  }
  return rv;
}

int rand(void) {
  return cl_mock_type(int);
}

/// Tests

static void prv_assert_key_is_equal_to_retrieved_key(const SM128BitKey *key, SMRootKeyType type) {
  cl_assert_equal_m(key, &s_retrieved_keys[type], sizeof(SM128BitKey));
}

static void prv_assert_key_is_equal_to_rng_key(const SM128BitKey *key, SMRootKeyType type) {
  int rng_start_output = type * RNG_ROUNDS;
  uint8_t rng_buffer[sizeof(SM128BitKey)];
  uint32_t *rngs = (uint32_t *)rng_buffer;
  for (int i = 0; i < RNG_ROUNDS; ++i) {
    rngs[i] = rng_start_output + i;
  }
  SM128BitKey *rng_key = (SM128BitKey *)rng_buffer;
  cl_assert_equal_m(key, rng_key, sizeof(SM128BitKey));
}

void test_ble_root_keys__initialize(void) {
  s_rng_output = 0;
  memset(s_stored_keys, 0, sizeof(SM128BitKey) * SMRootKeyTypeNum);
}

void test_ble_root_keys__cleanup(void) {
}

void test_ble_root_keys__has_existing_root_keys(void) {
  cl_will_return_count(bt_persistent_storage_get_root_key, true, 2);

  SM128BitKey keys[SMRootKeyTypeNum];
  ble_root_keys_get_and_generate_if_needed(keys);
  prv_assert_key_is_equal_to_retrieved_key(&keys[SMRootKeyTypeEncryption], SMRootKeyTypeEncryption);
  prv_assert_key_is_equal_to_retrieved_key(&keys[SMRootKeyTypeIdentity], SMRootKeyTypeIdentity);
}

void test_ble_root_keys__regenerate_if_key_not_present(void) {
  // Pretend one of the root keys isn't there:
  cl_will_return_count(bt_persistent_storage_get_root_key, true, 1);
  cl_will_return_count(bt_persistent_storage_get_root_key, false, 1);

  cl_will_return_count(rng_rand, true, RNG_ROUNDS * SMRootKeyTypeNum);

  cl_will_return_count(bt_persistent_storage_set_root_keys, true, 1);

  SM128BitKey keys[SMRootKeyTypeNum];
  ble_root_keys_get_and_generate_if_needed(keys);
  prv_assert_key_is_equal_to_rng_key(&keys[SMRootKeyTypeEncryption], SMRootKeyTypeEncryption);
  prv_assert_key_is_equal_to_rng_key(&keys[SMRootKeyTypeIdentity], SMRootKeyTypeIdentity);
  prv_assert_key_is_equal_to_rng_key(&s_stored_keys[SMRootKeyTypeEncryption], SMRootKeyTypeEncryption);
  prv_assert_key_is_equal_to_rng_key(&s_stored_keys[SMRootKeyTypeIdentity], SMRootKeyTypeIdentity);
}

void test_ble_root_keys__fall_back_to_rand(void) {
  // Pretend one of the root keys isn't there:
  cl_will_return_count(bt_persistent_storage_get_root_key, true, 1);
  cl_will_return_count(bt_persistent_storage_get_root_key, false, 1);

  cl_will_return_count(rng_rand, false, RNG_MAX_RETRIES);
  cl_will_return_count(rand, 0x55, sizeof(SM128BitKey));
  cl_will_return_count(rand, 0xaa, sizeof(SM128BitKey));

  cl_will_return_count(bt_persistent_storage_set_root_keys, true, 1);

  SM128BitKey keys[SMRootKeyTypeNum];
  ble_root_keys_get_and_generate_if_needed(keys);

  SM128BitKey rand_enc;
  SM128BitKey rand_id;
  memset(&rand_enc, 0x55, sizeof(SM128BitKey));
  memset(&rand_id, 0xaa, sizeof(SM128BitKey));
  cl_assert_equal_m(&keys[SMRootKeyTypeEncryption], &rand_enc, sizeof(SM128BitKey));
  cl_assert_equal_m(&keys[SMRootKeyTypeIdentity], &rand_id, sizeof(SM128BitKey));
  cl_assert_equal_m(&s_stored_keys[SMRootKeyTypeEncryption], &rand_enc, sizeof(SM128BitKey));
  cl_assert_equal_m(&s_stored_keys[SMRootKeyTypeIdentity], &rand_id, sizeof(SM128BitKey));
}
