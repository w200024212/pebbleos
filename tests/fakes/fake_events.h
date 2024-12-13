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

#include "kernel/events.h"

void fake_event_init(void);

PebbleEvent fake_event_get_last(void);

void fake_event_clear_last(void);

void fake_event_reset_count(void);

uint32_t fake_event_get_count(void);

void **fake_event_get_buffer(PebbleEvent *event);

typedef void (*FakeEventCallback)(PebbleEvent *event);
void fake_event_set_callback(FakeEventCallback cb);

