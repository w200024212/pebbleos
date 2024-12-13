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

#include "app_launch_reason.h"

#include "process_state/app_state/app_state.h"
#include "syscall/syscall.h"

AppLaunchReason app_launch_reason(void) {
  return sys_process_get_launch_reason();
}


uint32_t app_launch_get_args(void) {
  return sys_process_get_launch_args();
}
