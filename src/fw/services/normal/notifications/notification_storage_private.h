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

//! Notification storage file size
#define NOTIFICATION_STORAGE_FILE_SIZE (30 * 1024)

//! Minimum increment of space to free up when compressing.
//! The higher the value, the less often we need to compress,
//! but we will lose more notifications
#define NOTIFICATION_STORAGE_MINIMUM_INCREMENT_SIZE (NOTIFICATION_STORAGE_FILE_SIZE / 4)

