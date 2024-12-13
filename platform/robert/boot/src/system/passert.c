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

#include "passert.h"

#include "drivers/dbgserial.h"
#include "system/die.h"
#include "util/attributes.h"

#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static NORETURN prv_handle_passert_failed_vargs(const char* filename, int line_number,
    uintptr_t lr, const char* expr, const char* fmt, va_list fmt_args) {
  dbgserial_print("ASSERT: ");
  dbgserial_print(expr);
  dbgserial_print("  ");
  dbgserial_print(filename);
  dbgserial_print(":");
  dbgserial_print_hex(line_number);
  if (fmt) {
    dbgserial_print(" ");
    dbgserial_print(fmt);
  }
  dbgserial_putstr("");

  reset_due_to_software_failure();
}

static NORETURN prv_handle_passert_failed(const char* filename, int line_number,
    uintptr_t lr, const char *expr, const char* fmt, ...) {
  va_list fmt_args;
  va_start(fmt_args, fmt);

  prv_handle_passert_failed_vargs(filename, line_number, lr, expr, fmt, fmt_args);

  va_end(fmt_args);
}

void passert_failed(const char* filename, int line_number, const char* message, ...) {
  va_list fmt_args;
  va_start(fmt_args, message);

  prv_handle_passert_failed_vargs(filename, line_number,
    (uintptr_t)__builtin_return_address(0), "ASSERT", message, fmt_args);

  va_end(fmt_args);
}

void passert_failed_no_message(const char* filename, int line_number) {
  prv_handle_passert_failed(filename, line_number,
    (uintptr_t)__builtin_return_address(0), "ASSERTN", NULL);
}

void wtf(void) {
  uintptr_t saved_lr = (uintptr_t) __builtin_return_address(0);
  dbgserial_print("*** WTF ");
  dbgserial_print_hex(saved_lr);
  dbgserial_putstr("");
  reset_due_to_software_failure();
}

//! Assert function called by the STM peripheral library's
//! 'assert_param' method. See stm32f2xx_conf.h for more information.
void assert_failed(uint8_t* file, uint32_t line) {
  register uintptr_t lr __asm("lr");
  uintptr_t saved_lr = lr;

  prv_handle_passert_failed((const char*) file, line, saved_lr, "STM32", "STM32 peripheral library "
      "tripped an assert");
}
