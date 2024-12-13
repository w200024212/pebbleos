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

#include "applib/unobstructed_area_service_private.h"
#include "util/attributes.h"

void WEAK unobstructed_area_service_get_area(UnobstructedAreaState *state, GRect *area) { }

void WEAK unobstructed_area_service_will_change(int16_t current_y, int16_t final_y) { }

void WEAK unobstructed_area_service_change(int16_t current_y, int16_t final_y,
                                           AnimationProgress progress) { }

void WEAK unobstructed_area_service_did_change(int16_t final_y) { }
