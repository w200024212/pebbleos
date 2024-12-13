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

#include <stdbool.h>
#include <stdint.h>

//! Functions for controlling the display FPGA in bootloader mode, such as
//! early in the boot process before it is reconfigured in framebuffer mode.
//!
//! These functions all assume that all necessary GPIOs and the SPI peripheral
//! are configured correctly, and that the bootloader is already in bootloader
//! mode.

//! Display the Pebble logo and turn on the screen.
void boot_display_show_boot_splash(void);

//! Show the Pebble logo with a progress bar.
void boot_display_show_firmware_update_progress(
    uint32_t numerator, uint32_t denominator);

//! Show a sad-watch error.
bool boot_display_show_error_code(uint32_t error_code);

//! Black out the screen and prepare for power down.
void boot_display_screen_off(void);
