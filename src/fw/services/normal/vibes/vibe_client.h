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

#include "vibe_score.h"

typedef enum VibeClient {
  VibeClient_Notifications = 0,
  VibeClient_PhoneCalls,
  VibeClient_Alarms,
  VibeClient_AlarmsLPM
} VibeClient;

// Returns the appropriate vibe score for the client.
// This is determined from alert preferences.
VibeScore *vibe_client_get_score(VibeClient client);
