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

#include "process_management/app_manager.h"

#include "syscall/syscall.h"

typedef struct {
  ListNode *head; //! Pointer to the Animation struct that is the animation that is scheduled
                  //! first.
  AppTimer* timer_handle;

  //! The delay the animation scheduler uses between finishing a frame and starting a new one.
  //! Derived from actual rendering/calculation times, using a PID-like control algorithm.
  uint32_t last_delay_ms;
  uint32_t last_frame_time; //! Absolute RTC time of the moment the last animation frame started.
} AnimationLegacy2Scheduler;

void animation_legacy2_private_init_scheduler(AnimationLegacy2Scheduler* scheduler);

void animation_legacy2_private_unschedule_all(AppTaskCtxIdx app_task_ctx_idx);
