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

static const uint32_t ERROR_NO_ACTIVE_ERROR = 0;

// FW Errors
static const uint32_t ERROR_STUCK_BUTTON  = 0xfe504501;
static const uint32_t ERROR_BAD_SPI_FLASH = 0xfe504502;
static const uint32_t ERROR_CANT_LOAD_FW = 0xfe504503;
static const uint32_t ERROR_RESET_LOOP = 0xfe504504;
static const uint32_t ERROR_BAD_RESOURCES = 0xfe504505;

// BT Errors
static const uint32_t ERROR_CANT_LOAD_BT = 0xfe504510;
static const uint32_t ERROR_CANT_START_LSE = 0xfe504511;
static const uint32_t ERROR_CANT_START_ACCEL = 0xfe504512;

static const uint32_t ERROR_LOW_BATTERY = 0xfe504520;

