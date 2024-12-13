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

#include <stdint.h>

//! @file fpc_pinstrap.h
//!
//! This file implements an API to read the pinstrap values for an attached FPC (flexible printed
//! circuit). These values are used for version identification so we can figure out which version
//! of FPC is connected to our main PCB.

#define FPC_PINSTRAP_NOT_AVAILABLE 0xff

//! @return uint8_t a value between 0 and 8 to represent the pinstrap value. If the pinstrap
//!                 value isn't valid on this platform, FPC_PINSTRAP_NOT_AVAILABLE is returned.
uint8_t fpc_pinstrap_get_value(void);
