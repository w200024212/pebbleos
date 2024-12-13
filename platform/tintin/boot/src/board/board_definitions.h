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

// FIXME: PBL-21049 Fix platform abstraction and board definition scheme
#if BOARD_EV2_4
#include "board_ev2_4.h" // shipped as Pebble 1.0
#elif BOARD_BB2
#include "board_bb2.h"
#elif BOARD_V1_5
#include "board_v1_5.h" // prototypes for Pebble 1.3/Pebble 1.5
#elif BOARD_V2_0
#include "board_v2_0.h" // prototypes for Pebble 2.0
#else
#error "Unknown board definition"
#endif
