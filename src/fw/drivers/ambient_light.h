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

//! Light level enum
typedef enum AmbientLightLevel {
  AmbientLightLevelUnknown = 0,
  AmbientLightLevelVeryDark,
  AmbientLightLevelDark,
  AmbientLightLevelLight,
  AmbientLightLevelVeryLight,
} AmbientLightLevel;

#define AMBIENT_LIGHT_LEVEL_ENUM_COUNT (AmbientLightLevelVeryLight + 1)

static const uint32_t AMBIENT_LIGHT_LEVEL_MAX  = 4096;   // max 12 bits

/** Initialize the ambient light sensor */
void ambient_light_init(void);

/** get the ambient light level scaled between 0 and AMBIENT_LIGHT_LEVEL_MAX
 */
uint32_t ambient_light_get_light_level(void);

//! get the threshold between light and dark
uint32_t ambient_light_get_dark_threshold(void);

//! set the threshold between light and dark
void ambient_light_set_dark_threshold(uint32_t new_threshold);

//! figure out whether it is light outside
bool ambient_light_is_light();

//! Convert a light level obtained from ambient_light_get_light_level() into an
//! AmbientLightLevel enum value.
//! @param[in] light_level the raw light level reading obtained from ambient_light_get_light_level
AmbientLightLevel ambient_light_level_to_enum(uint32_t light_level);
