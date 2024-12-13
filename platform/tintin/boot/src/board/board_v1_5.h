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

#include "drivers/button.h"
#include "util/misc.h"

#include "stm32f2xx_rcc.h"
#include "stm32f2xx_gpio.h"
#include "stm32f2xx_syscfg.h"

static const BoardConfigPower BOARD_CONFIG_POWER = {
  .vusb_stat = {
    .gpio = GPIOC,
    .gpio_pin = GPIO_Pin_13,
  },
  .wake_on_usb_power = true
};

static const BoardConfigButton BOARD_CONFIG_BUTTON = {
  .buttons = {
    [BUTTON_ID_BACK]    = { "Back",   GPIOC, GPIO_Pin_3 },
    [BUTTON_ID_UP]      = { "Up",     GPIOA, GPIO_Pin_2 },
    [BUTTON_ID_SELECT]  = { "Select", GPIOC, GPIO_Pin_6 },
    [BUTTON_ID_DOWN]    = { "Down",   GPIOA, GPIO_Pin_1 },
  },

  .button_com = { GPIOA, GPIO_Pin_0 },
};
