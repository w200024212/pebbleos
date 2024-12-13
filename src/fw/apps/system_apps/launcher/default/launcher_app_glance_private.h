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

#include "applib/ui/kino/kino_reel.h"

//! Get the size of the provided reel that implements how a launcher app glance should be drawn.
//! @param reel The reel that implements how a glance should be drawn
//! @return The size of the reel
GSize launcher_app_glance_get_size_for_reel(KinoReel *reel);
