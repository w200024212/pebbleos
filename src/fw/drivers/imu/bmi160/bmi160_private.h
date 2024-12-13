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
#include "drivers/gpio.h"
#include "drivers/periph_config.h"
#include "drivers/spi.h"

//! Ask the chip to accept input from the SPI bus. Required after issuing a soft reset.
void bmi160_enable_spi_mode(void);
void bmi160_begin_burst(uint8_t addr);
void bmi160_end_burst(void);

uint8_t bmi160_read_reg(uint8_t reg);
uint16_t bmi160_read_16bit_reg(uint8_t reg);
void bmi160_write_reg(uint8_t reg, uint8_t value);
