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

#if defined(MICRO_FAMILY_STM32F2)
#include "stm32f2xx_gpio.h"
#elif defined(MICRO_FAMILY_STM32F4)
#include "stm32f4xx_gpio.h"
#endif

#include "board/board.h"

void gpio_use(GPIO_TypeDef* GPIOx);
void gpio_release(GPIO_TypeDef* GPIOx);

//! Initialize a GPIO as an output.
//!
//! @param pin_config the BOARD_CONFIG pin configuration struct
//! @param otype the output type of the pin (GPIO_OType_PP or GPIO_OType_OD)
//! @param speed the output slew rate
//! @note The slew rate should be set as low as possible for the
//!       pin function to minimize ringing and RF interference.
void gpio_output_init(OutputConfig pin_config, GPIOOType_TypeDef otype,
                      GPIOSpeed_TypeDef speed);

//! Assert or deassert the output pin.
//!
//! Asserting the output drives the pin high if pin_config.active_high
//! is true, and drives it low if pin_config.active_high is false.
void gpio_output_set(OutputConfig pin_config, bool asserted);

//! Configure a GPIO alternate function.
//!
//! @param pin_config the BOARD_CONFIG pin configuration struct
//! @param otype the output type of the pin (GPIO_OType_PP or GPIO_OType_OD)
//! @param speed the output slew rate
//! @param pupd pull-up or pull-down configuration
//! @note The slew rate should be set as low as possible for the
//!       pin function to minimize ringing and RF interference.
void gpio_af_init(AfConfig af_config, GPIOOType_TypeDef otype,
                  GPIOSpeed_TypeDef speed, GPIOPuPd_TypeDef pupd);
