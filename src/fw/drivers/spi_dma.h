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

//! Note: DMA isn't explicitly supported via this API.
//! These functions exist to allow the caller to manager their own
//! DMA and enable it without accessing the SPI configuration directly

//! Enable/Disable TX DMA for the given device
void spi_ll_slave_set_tx_dma(const SPISlavePort *slave, bool enable);

//! Enable/Disable RX DMA for the given device
void spi_ll_slave_set_rx_dma(const SPISlavePort *slave, bool enable);

//! Enable the SPI device
void spi_ll_slave_spi_enable(const SPISlavePort *slave);

//! Disable the SPI device
void spi_ll_slave_spi_disable(const SPISlavePort *slave);
