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

#include "drivers/mcu_reboot_reason.h"
#include <stdint.h>

// TODO: Eventually move debug logging back to hashed logging
// Currently broken out to directly log strings without hashing
#ifdef PBL_LOG_ENABLED
  #define DEBUG_LOG(level, fmt, ...) \
      pbl_log(level, __FILE__, __LINE__, fmt, ## __VA_ARGS__)
#else
  #define DEBUG_LOG(level, fmt, ...)
#endif

void debug_init(McuRebootReason reason);

void debug_print_last_launched_app(void);

