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

#include "applib/graphics/gtypes.h"

//! @file status_bar_legacy2.h
//!
//! This file implements a 2.x status bar for backwards compatibility with apps compiled with old
//! firmwares.

#define STATUS_BAR_HEIGHT 16

#define STATUS_BAR_FRAME GRect(0, 0, DISP_COLS, STATUS_BAR_HEIGHT)
