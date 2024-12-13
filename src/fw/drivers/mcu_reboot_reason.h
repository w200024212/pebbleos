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
#include <stdint.h>

typedef struct McuRebootReason {
  union {
    struct {
      bool brown_out_reset:1;
      bool pin_reset:1;
      bool power_on_reset:1;
      bool software_reset:1;
      bool independent_watchdog_reset:1;
      bool window_watchdog_reset:1;
      bool low_power_manager_reset:1;
      uint8_t reserved:1;
    };
    uint8_t reset_mask;
  };
} McuRebootReason;
