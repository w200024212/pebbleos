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

#include "kernel/memory_layout.h"

const uint32_t __app_stack_start__;
const uint32_t __app_stack_end__;
const uint32_t __isr_stack_start__;
const uint32_t __kernel_bg_stack_start__;
const uint32_t __kernel_main_stack_start__;
const uint32_t __stack_guard_size__;
const uint32_t __worker_stack_start__;
const uint32_t __privileged_functions_start__;
const uint32_t __privileged_functions_size__;
const uint32_t __unpriv_ro_bss_start__;
const uint32_t __unpriv_ro_bss_size__;
const uint32_t __unpriv_ro_data_start__;
const uint32_t __unpriv_ro_data_size__;
const uint32_t __APP_RAM_start__;
const uint32_t __APP_RAM_size__;
const uint32_t __WORKER_RAM_start__;
const uint32_t __WORKER_RAM_size__;
const uint32_t __FLASH_start__;
const uint32_t __FLASH_size__;

void mpu_enable(void) {
}

MpuRegion mpu_get_region(int region_num) {
  return (MpuRegion) { 0 };
}

void mpu_set_region(const MpuRegion* region) {
}
