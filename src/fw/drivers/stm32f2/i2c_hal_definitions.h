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

typedef enum I2CDutyCycle {
  I2CDutyCycle_16_9,
  I2CDutyCycle_2
} I2CDutyCycle;

typedef struct I2CBusHal {
  I2C_TypeDef *const i2c;
  uint32_t clock_ctrl;  ///< Peripheral clock control flag
  uint32_t clock_speed; ///< Bus clock speed
  I2CDutyCycle duty_cycle;  ///< Bus clock duty cycle in fast mode
  IRQn_Type ev_irq_channel; ///< I2C Event interrupt (One of X_IRQn). For example, I2C1_EV_IRQn.
  IRQn_Type er_irq_channel; ///< I2C Error interrupt (One of X_IRQn). For example, I2C1_ER_IRQn.
} I2CBusHal;

void i2c_hal_event_irq_handler(I2CBus *device);
void i2c_hal_error_irq_handler(I2CBus *device);
