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

#define STM32F2_COMPATIBLE
#define STM32F4_COMPATIBLE
#include <mcu.h>

bool bma255_selftest(void);

void bma255_gpio_init(void);

void bma255_enable_spi_clock(void);

void bma255_disable_spi_clock(void);

uint8_t bma255_send_and_receive_byte(uint8_t byte);

void bma255_send_byte(uint8_t byte);

void bma255_prepare_txn(uint8_t address);

void bma255_end_txn(void);

void bma255_burst_read(uint8_t address, uint8_t *data, size_t len);

uint8_t bma255_read_register(uint8_t address);

void bma255_write_register(uint8_t address, uint8_t data);

void bma255_read_modify_write(uint8_t reg, uint8_t value, uint8_t mask);
