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

//! @file fake_animation.h
//!
//! Simple fake of the Animation code. Not intended to be a complete drop in replacement, but good
//! enough for some simple tests.

#include "applib/ui/animation_private.h"

//! @return A pointer to the first animation that was created since we last called
//! fake_animation_cleanup
Animation * fake_animation_get_first_animation(void);

//! @return The next animation after the supplied animation. Animations form a link list based on
//! creation time, and that list can be walked by combining this function with
//! fake_animation_get_first_animation
Animation * fake_animation_get_next_animation(Animation *animation);

//! Cleans up all fake animation state. Use between tests to ensure a clean slate.
void fake_animation_cleanup(void);

//! Runs an animation to completion by scheduling it, setting its elapsed to its duration, and then
//! unscheduling it.
//! @param animation The animation to run to completion.
void fake_animation_complete(Animation *animation);
