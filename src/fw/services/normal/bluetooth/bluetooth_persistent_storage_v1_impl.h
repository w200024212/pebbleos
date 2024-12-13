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

#include <bluetooth/bluetooth_types.h>
#include <bluetooth/sm_types.h>
#include <util/attributes.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct PACKED BtPersistLEPairingInfo {
  struct PACKED {
    uint16_t div;
    uint16_t ediv;
  } local_encryption_info;

  uint8_t rsvd1[4];

  struct PACKED {
    SMLongTermKey ltk;
    uint64_t rand;
    uint16_t ediv;
  } remote_encryption_info;

  uint8_t rsvd2[6];

  SMIdentityResolvingKey irk;
  BTDeviceInternal identity;

  SMConnectionSignatureResolvingKey csrk;

  //! True if local_encryption_info is valid
  bool is_local_encryption_info_valid:1;

  //! True if remote_encryption_info is valid
  bool is_remote_encryption_info_valid:1;

  //! True if irk and identity are valid
  bool is_remote_identity_info_valid:1;

  //! True if csrk is valid
  bool is_remote_signing_info_valid:1;

  uint8_t rsvd3:4;
  uint8_t rsvd4[7];
} BtPersistLEPairingInfo;

static void bt_persistent_storage_assign_persist_pairing_info(BtPersistLEPairingInfo *out,
                                                              const SMPairingInfo *in) {
  *out = (BtPersistLEPairingInfo) {};
  out->local_encryption_info.div = in->local_encryption_info.div;
  out->local_encryption_info.ediv = in->local_encryption_info.ediv;
  out->remote_encryption_info.ltk = in->remote_encryption_info.ltk;
  out->remote_encryption_info.rand = in->remote_encryption_info.rand;
  out->remote_encryption_info.ediv = in->remote_encryption_info.ediv;
  out->irk = in->irk;
  out->identity = in->identity;
  out->csrk = in->csrk;
  out->is_local_encryption_info_valid = in->is_local_encryption_info_valid;
  out->is_remote_encryption_info_valid = in->is_remote_encryption_info_valid;
  out->is_remote_identity_info_valid = in->is_remote_identity_info_valid;
  out->is_remote_signing_info_valid = in->is_remote_signing_info_valid;
}

static void bt_persistent_storage_assign_sm_pairing_info(SMPairingInfo *out,
                                                         const BtPersistLEPairingInfo *in) {
  *out = (SMPairingInfo) {};
  out->local_encryption_info.div = in->local_encryption_info.div;
  out->local_encryption_info.ediv = in->local_encryption_info.ediv;
  out->remote_encryption_info.ltk = in->remote_encryption_info.ltk;
  out->remote_encryption_info.rand = in->remote_encryption_info.rand;
  out->remote_encryption_info.ediv = in->remote_encryption_info.ediv;
  out->irk = in->irk;
  out->identity = in->identity;
  out->csrk = in->csrk;
  out->is_local_encryption_info_valid = in->is_local_encryption_info_valid;
  out->is_remote_encryption_info_valid = in->is_remote_encryption_info_valid;
  out->is_remote_identity_info_valid = in->is_remote_identity_info_valid;
  out->is_remote_signing_info_valid = in->is_remote_signing_info_valid;
}
