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

#include "stm32f4xx_gpio.h"

#include "board/board.h"

void gpio_enable_all(void);
void gpio_disable_all(void);
void gpio_af_init(const AfConfig *af_config, GPIOOType_TypeDef otype, GPIOSpeed_TypeDef speed,
                  GPIOPuPd_TypeDef pupd);
