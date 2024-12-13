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

#include <inttypes.h>
#include <stdbool.h>

//! Version of the welcoming of the user to the normal firmware
typedef enum WelcomeVersion {
  //! Initial version or never launched normal firmware
  WelcomeVersion_InitialVersion = 0,
  //! 4.x Normal Firmware
  WelcomeVersion_4xNormalFirmware = 1,

  WelcomeVersionCount,
  //! WelcomeVersion is an increasing version number. WelcomeVersionCurrent must
  //! not decrement. This should ensure that the current version is always the latest.
  WelcomeVersionCurrent = WelcomeVersionCount - 1,
} WelcomeVersion;

//! Welcomes the user to a newer normal firmware they have not used yet if they have used an older
//! normal firmware and the newer normal firmware warrants a notification.
//! @note This must be called before getting started completed is set in shared prf storage.
void welcome_push_notification(bool factory_reset_or_first_use);

//! Set the welcome version. This is persisted in shell prefs.
void welcome_set_welcome_version(uint8_t version);

//! Get the welcome version
uint8_t welcome_get_welcome_version(void);
