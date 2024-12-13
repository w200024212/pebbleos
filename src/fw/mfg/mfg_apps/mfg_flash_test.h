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

// To add new tests, update the following:
// 1. FlashTestCaseType enum
// 2. Update run_flash_test_case to include test
// 3. Update test_window_load in flash_test.c with test case name
// 4. Update flash_test_window_load in flash_test.c with test case menu item
// 5. Update prompt_commands.c if necessary
typedef enum {
  FLASH_TEST_CASE_RUN_DATA_TEST =         0,
  FLASH_TEST_CASE_RUN_ADDR_TEST =         1,
  FLASH_TEST_CASE_RUN_STRESS_ADDR_TEST =  2,
  FLASH_TEST_CASE_RUN_PERF_DATA_TEST =    3,
  FLASH_TEST_CASE_RUN_SWITCH_MODE_ASYNC = 4,
  FLASH_TEST_CASE_RUN_SWITCH_MODE_SYNC_BURST = 5,
  // Add new test cases above this line
  FLASH_TEST_CASE_NUM_MENU_ITEMS
} FlashTestCaseType;

typedef enum {
FLASH_TEST_SUCCESS           =  0,
FLASH_TEST_ERR_OTHER         = -1,
FLASH_TEST_ERR_ERASE         = -2,
FLASH_TEST_ERR_DATA_WRITE    = -3,
FLASH_TEST_ERR_ADDR_RANGE    = -4,
FLASH_TEST_ERR_STUCK_AT_HIGH = -5,
FLASH_TEST_ERR_STUCK_AT_LOW  = -6,
FLASH_TEST_ERR_OOM           = -7,
FLASH_TEST_ERR_UNSUPPORTED   = -8,
FLASH_TEST_ERR_SKIP          = -9,
} FlashTestErrorType;

// This function explicitly stop a test case if it is currently running. Currently this only affects
//   the stress test.
extern void stop_flash_test_case( void );

extern FlashTestErrorType run_flash_test_case(FlashTestCaseType test_case_num, uint32_t iterations);
