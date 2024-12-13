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
#include <setjmp.h>

/*!
  Initialize the fake SPI flash region.

  @param offset the offset at which this fake region of flash begins.
  @param length the length of this fake region of flash.
 */
void fake_spi_flash_init(uint32_t offset, uint32_t length);

//! Add data to the fake spi flash from a file on your local filesystem
void fake_spi_flash_populate_from_file(char *path, uint32_t offset);

//! Cleanup the fake SPI flash region, freeing all resources.
void fake_spi_flash_erase(void);

//! Cleanup the fake SPI flash region, freeing all resources.
void fake_spi_flash_cleanup(void);

//! Force the SPI flash to fail at some point in the future, jumping back to
//! the given jmp_buf when it does so. This is intended for use in verifying
//! the atomicity of algorithms which are purported to be so.
void fake_spi_flash_force_future_failure(int after_n_bytes, jmp_buf *retire_to);

void fake_flash_assert_region_untouched(uint32_t start_addr, uint32_t length);

uint32_t fake_flash_write_count(void);
uint32_t fake_flash_erase_count(void);
