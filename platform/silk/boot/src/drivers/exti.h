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

#include "board/board.h"

typedef enum {
  ExtiTrigger_Rising,
  ExtiTrigger_Falling,
  ExtiTrigger_RisingFalling
} ExtiTrigger;

//! See section 12.2.5 "External interrupt/event line mapping" in the STM32F2 reference manual
typedef enum {
  ExtiLineOther_RTCAlarm = 17,
  ExtiLineOther_RTCWakeup = 22
} ExtiLineOther;

typedef void (*ExtiHandlerCallback)(void);

//! Configures the given EXTI and NVIC for the given configuration.
void exti_configure_pin(ExtiConfig cfg, ExtiTrigger trigger, ExtiHandlerCallback cb);
//! Configures the given EXTI and NVIC for the given configuration.
void exti_configure_other(ExtiLineOther exti_line, ExtiTrigger trigger);

static inline void exti_enable(ExtiConfig config);
static inline void exti_disable(ExtiConfig config);

void exti_enable_other(ExtiLineOther);
void exti_disable_other(ExtiLineOther);

#include "exti.inl.h"
