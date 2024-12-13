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

#include "test_args_rx.h"
#include "test_args_tx.h"

#include "applib/app.h"
#include "kernel/event_loop.h"
#include "process_management/app_manager.h"
#include "process_management/process_manager.h"
#include "system/logging.h"

static void s_main(void) {
  const TestArgsData *args = process_manager_get_current_process_args();
  if (args == NULL) {
    PBL_LOG(LOG_LEVEL_DEBUG, "Got no args.");
  } else {
    PBL_LOG(LOG_LEVEL_DEBUG, "Got argument 0x%x", args->data);
  }
}

const PebbleProcessMd* test_args_receiver_get_app_info() {
  static const PebbleProcessMdSystem test_args_receiver_demo_app_info = {
    .common.uuid = {0x48, 0xBB, 0xB5, 0x04, 0x5A, 0x56, 0x40, 0x73, 0xAF,
      0xEA, 0x5D, 0x83, 0x8D, 0x43, 0x01, 0xA4},
    .common.main_func = s_main,
    .name = "Args Receiver Demo"
  };
  return (const PebbleProcessMd*) &test_args_receiver_demo_app_info;
}
