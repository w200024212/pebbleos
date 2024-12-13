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

#include "board/board.h"

#include <stdbool.h>
#include <stdint.h>

// TODO: Calling this ICE40LP kind of sucks, but I can't think of anything better without doing a
// whole big display system refactor, so we're keeping it as ICE40LP.
typedef struct ICE40LPDeviceState {
} ICE40LPDeviceState;

typedef const struct ICE40LPDevice {
  ICE40LPDeviceState *state;

  SPISlavePort *spi_port;
  uint32_t base_spi_frequency;
  uint32_t fast_spi_frequency;

  const OutputConfig creset;
  const InputConfig cdone;
  const InputConfig busy;
  const ExtiConfig cdone_exti;
  const ExtiConfig busy_exti;

  bool use_6v6_rail;
} ICE40LPDevice;
