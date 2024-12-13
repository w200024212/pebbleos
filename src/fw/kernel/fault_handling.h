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
#include "system/reboot_reason.h"

typedef struct Heap Heap;

NORETURN trigger_oom_fault(size_t bytes, uint32_t lr, Heap *heap_ptr);
NORETURN trigger_fault(RebootReasonCode reason_code, uint32_t lr);
void enable_fault_handlers(void);

