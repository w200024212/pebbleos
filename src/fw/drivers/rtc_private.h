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

//! @file rtc_private.h
//!
//! Functions private to implementations of RTC drivers for stm32 platforms

//! Called by rtc_init to initialize the clock source.
//!
//! Warning! In some cases this function may detect an edge case and reset the system to address
//! it! See the implementation for details.
//!
//! @return True if we managed to correctly get onto the LSE, false otherwise
bool rtc_init_config_clock_source(void);

//! Configure the LSE oscillator component of the RCC
void rtc_init_config_lse_clock_source(void);

//! Verify that the clock source is set up correctly.
//!
//! Warning! In some cases this function may detect an edge case and reset the system to address
//! it! See the implementation for details.
void rtc_init_verify_clock_source_config(void);

//! Enable access to the RTC's backup registers
void rtc_enable_backup_regs(void);
