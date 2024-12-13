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

#include "services/normal/timeline/item.h"

void notifications_handle_ancs_message(TimelineItem *notification);

void notifications_handle_ancs_notification_removed(uint32_t ancs_uid);

void notifications_add_notification(TimelineItem *notification);

////////////////////////////////////////////////////////////////////////////////////////////////////
// Fake manipulation:

//! Resets the fake (i.e. ANCS count)
void fake_kernel_services_notifications_reset(void);

//! @return Number of times notifications_handle_ancs_message() was called.
uint32_t fake_kernel_services_notifications_ancs_notifications_count(void);

//! @return Number of times notifications_handle_notification_acted_upon() was called.
uint32_t fake_kernel_services_notifications_acted_upon_count(void);
