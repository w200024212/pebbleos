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

//! Forward declaration to internal, implementation specific state.
typedef struct PairingUserConfirmationCtx PairingUserConfirmationCtx;

//! Confirms a pairing request.
//! @param[in] ctx The pairing request context, as previously passed to
//! bt_driver_cb_pairing_confirm_handle_request.
//! @param[in] is_confirmed Pass true if the user confirmed the pairing.
void bt_driver_pairing_confirm(const PairingUserConfirmationCtx *ctx,
                               bool is_confirmed);

//! @param[in] ctx Pointer to opaque BT-driver-implementation specific context. The function can
//! use the pointer value this to distinguish one pairing process from another, but the pointer
//! should NOT be dereferenced by the FW side. Aside the fact that the struct is internal to
//! the FW and therefore shouldn't be able to look inside it, the memory can be free'd at all times
//! by the BT driver implementation. For example when the pairing process times out, the BT driver
//! might free the memory that ctx is pointing to.
//! @param[in] device_name Optional device name of the device that is attempting to pair. Pass NULL
//! if the device name is not available.
//! @param[in] confirmation_token Optional confirmation token. Pass NULL if not available.
//! @note This function should immediately copy the device name and confirmation token, so the
//! buffers do not have to continue existing after this function returns.
extern void bt_driver_cb_pairing_confirm_handle_request(const PairingUserConfirmationCtx *ctx,
                                                        const char *device_name,
                                                        const char *confirmation_token);

//! @param[in] ctx See bt_driver_cb_pairing_confirm_handle_request
//! @param[in] success True if the pairing process finished successfully.
extern void bt_driver_cb_pairing_confirm_handle_completed(const PairingUserConfirmationCtx *ctx,
                                                          bool success);
