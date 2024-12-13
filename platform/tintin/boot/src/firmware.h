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

#include "stm32f2xx.h"

#define FW_OLDWORLD_OFFSET (0x10000)
#define FW_NEWWORLD_OFFSET (0x04000)
#define FW_WORLD_DIFFERENCE (FW_OLDWORLD_OFFSET - FW_NEWWORLD_OFFSET)

#define FIRMWARE_OLDWORLD_BASE (FLASH_BASE + FW_OLDWORLD_OFFSET)
#define FIRMWARE_NEWWORLD_BASE (FLASH_BASE + FW_NEWWORLD_OFFSET)

// Byte offset of NeWo in firmware
#define FW_IDENTIFIER_OFFSET (28)

bool firmware_is_new_world(void* base);
