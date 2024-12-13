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

//! Initial firmware startup, contains the vector table that the bootloader loads.
//! Based on "https://github.com/pfalcon/cortex-uni-startup/blob/master/startup.c"
//! by Paul Sokolovsky (public domain)

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "util/attributes.h"

//! These symbols are defined in the linker script for use in initializing
//! the data sections. uint8_t since we do arithmetic with section lengths.
//! These are arrays to avoid the need for an & when dealing with linker symbols.
extern uint8_t __data_load_start[];
extern uint8_t __data_start[];
extern uint8_t __data_end[];
extern uint8_t __bss_start[];
extern uint8_t __bss_end[];
extern uint8_t _estack[];

//! Bootloader entry point, ResetHandler calls this
extern int boot_main(void);

//! STM32 system initialization function, defined in the standard peripheral library
extern void SystemInit(void);

//! We don't use any interrupts in the bootloader so we map the core interrupts to
//! the HardFault_Handler to get useful debugging info if something goes wrong
extern void HardFault_Handler(void);

//! This function is what gets called when the processor first
//! starts execution following a reset event. The data and bss
//! sections are initialized, then we call the firmware's main
//! function
void Reset_Handler(void) {
  // Copy data section from flash to RAM
  memcpy(__data_start, __data_load_start, __data_end - __data_start);

  // Clear the bss section, assumes .bss goes directly after .data
  memset(__bss_start, 0, __bss_end - __bss_start);

  boot_main();

  // Main shouldn't return
  while (true) {}
}

EXTERNALLY_VISIBLE SECTION(".isr_vector") void *vector_table[] = {
  _estack,
  Reset_Handler,
  HardFault_Handler,
  HardFault_Handler,
  HardFault_Handler,
  HardFault_Handler,
  HardFault_Handler,
  0,
  0,
  0,
  0,
  HardFault_Handler,
  HardFault_Handler,
  0,
  HardFault_Handler,
  HardFault_Handler
};
