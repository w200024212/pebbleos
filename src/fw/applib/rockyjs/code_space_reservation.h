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

#include "util/attributes.h"

#include <stdint.h>

/**
 * As we are running pretty low on space on some platforms, we want to reserve some code space
 * for future use on the rocky project so that we can ensure there is space to implement APIs
 * uniformly on all platforms. Start with 15K and we will dwindle this down as we continue to
 * work on the rocky / jerryscript support.
 *
 * Modification Log:
 *   15360 : Starting point
 *   13232 : Jerryscript upstream merge on Sept 14
 *   12620 : postMessage() re-implementation
 *
 */

USED const uint8_t ROCKY_RESERVED_CODE_SPACE[12620] = {};
