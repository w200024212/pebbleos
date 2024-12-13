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

#include "services/normal/activity/activity.h"

void workout_utils_send_abandoned_workout_notification(void);

const char* workout_utils_get_name_for_activity(ActivitySessionType type);

const char* workout_utils_get_detection_text_for_activity(ActivitySessionType type);

bool workout_utils_find_ongoing_activity_session(ActivitySession *session_out);
