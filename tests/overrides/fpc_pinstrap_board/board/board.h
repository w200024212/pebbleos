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

#include <stdint.h>

typedef void* GPIO_TypeDef;
#define GPIO_Port_NULL ((GPIO_TypeDef*) 0)
#define GPIOA          ((GPIO_TypeDef*) 1)

enum {
  GPIO_Pin_1,
  GPIO_Pin_2
};

typedef enum {
  GPIO_OType_PP,
  GPIO_OType_OD
} GPIOOType_TypeDef;

typedef void* GPIOSpeed_TypeDef;

typedef enum {
  GPIO_PuPd_NOPULL,
  GPIO_PuPd_UP,
  GPIO_PuPd_DOWN
} GPIOPuPd_TypeDef;

typedef struct {
} AfConfig;

typedef struct {
} OutputConfig;

typedef struct {
  GPIO_TypeDef* const gpio; ///< One of GPIOX. For example, GPIOA.
  const uint32_t gpio_pin; ///< One of GPIO_Pin_X.
} InputConfig;

typedef struct {
  const InputConfig fpc_pinstrap_1;
  const InputConfig fpc_pinstrap_2;
} BoardConfig;

static const BoardConfig BOARD_CONFIG = {
  .fpc_pinstrap_1 = { GPIOA, GPIO_Pin_1 },
  .fpc_pinstrap_2 = { GPIOA, GPIO_Pin_2 },
};
