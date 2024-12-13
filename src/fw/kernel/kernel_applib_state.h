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

#include "applib/ui/animation_private.h"
#include "kernel/logging_private.h"
#include "applib/accel_service_private.h"
#include "applib/tick_timer_service_private.h"
#include "applib/compass_service_private.h"
#include "applib/battery_state_service.h"
#include "applib/battery_state_service_private.h"
#include "applib/connection_service.h"
#include "applib/connection_service_private.h"

void kernel_applib_init(void);

AnimationState *kernel_applib_get_animation_state(void);

LogState *kernel_applib_get_log_state(void);

void kernel_applib_release_log_state(LogState *state);

CompassServiceConfig **kernel_applib_get_compass_config(void);

EventServiceInfo* kernel_applib_get_event_service_state(void);

TickTimerServiceState *kernel_applib_get_tick_timer_service_state(void);

ConnectionServiceState* kernel_applib_get_connection_service_state(void);

BatteryStateServiceState* kernel_applib_get_battery_state_service_state(void);

struct Layer;
typedef struct Layer Layer;

Layer** kernel_applib_get_layer_tree_stack(void);
