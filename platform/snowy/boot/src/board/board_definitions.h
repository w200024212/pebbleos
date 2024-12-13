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

#if BOARD_SNOWY_BB
#include "board_snowy_bb.h" // prototypes for Snowy bigboard
#elif BOARD_SNOWY_EVT
#include "board_snowy_evt.h" // prototypes for Snowy EVT
#elif BOARD_SNOWY_EVT2
#include "board_snowy_evt2.h" // prototypes for Snowy EVT2
#elif BOARD_SPALDING
#include "board_snowy_evt2.h" // Close enough
#else
#error "Unknown board definition"
#endif
