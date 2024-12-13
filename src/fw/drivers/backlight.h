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

typedef enum {
  LEDEnablerNone = (1 << 0),
  LEDEnablerBacklight = (1 << 1),
  LEDEnablerHRM = (1 << 2),
} LEDEnabler;

// The light brightness can vary between LIGHT_BRIGHTNESS_OFF and LIGHT_BRIGHTNESS_ON
#define BACKLIGHT_BRIGHTNESS_OFF  0x0000
#define BACKLIGHT_BRIGHTNESS_MAX  0x4000

void backlight_init(void);

//! @param brightness a number between BACKLIGHT_BRIGHTNESS_OFF and BACKLIGHT_BRIGHTNESS_ON
void backlight_set_brightness(uint16_t brightness);

//! On some boards, the LED enable gpio is actually a toggle for 4.5v.
//! Other portions of the system may require this to be enabled in order to function.
//! Keep track of who is using the LED enable so that way we don't turn it off on them.
//! Those components which may need to toggle LED Enable are listed in \ref LEDEnabler.
void led_enable(LEDEnabler enabler);

void led_disable(LEDEnabler enabler);
