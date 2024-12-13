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
#include <stdint.h>

#include "kernel/events.h"

void firmware_update_init(void);

unsigned int firmware_update_get_percent_progress(void);

void firmware_update_event_handler(PebbleSystemMessageEvent* event);
void firmware_update_pb_event_handler(PebblePutBytesEvent *event);

typedef enum {
  FirmwareUpdateStopped = 0,
  FirmwareUpdateRunning = 1,
  FirmwareUpdateCancelled = 2,
  FirmwareUpdateFailed = 3,
} FirmwareUpdateStatus;

FirmwareUpdateStatus firmware_update_current_status(void);

bool firmware_update_is_in_progress(void);
