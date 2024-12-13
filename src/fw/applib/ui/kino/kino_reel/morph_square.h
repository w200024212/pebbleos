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

//! A KinoReel that can transform an image to a square or an image to another
//! with a square as an intermediate.
//! @param from_reel KinoReel to begin with
//! @param take_ownership true if this KinoReel will free `image` when destroyed.
//! @return a morph to square KinoReel
//! @see gpoint_attract_to_square
KinoReel *kino_reel_morph_square_create(KinoReel *from_reel, bool take_ownership);
