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

typedef enum {
  AMSAnalyticsEventErrorReserved = 0,
  // Lifecycle
  AMSAnalyticsEventErrorDiscovery = 1,
  AMSAnalyticsEventErrorSubscribe = 2,
  AMSAnalyticsEventErrorMusicServiceConnect = 3,
  AMSAnalyticsEventErrorRegisterEntityWrite = 4,
  AMSAnalyticsEventErrorRegisterEntityWriteResponse = 5,
  AMSAnalyticsEventErrorOtherWriteResponse = 6,
  // Updates
  AMSAnalyticsEventErrorPlayerVolumeUpdate = 7,
  AMSAnalyticsEventErrorPlayerPlaybackInfoUpdate = 8,
  AMSAnalyticsEventErrorPlayerPlaybackInfoFloatParse = 9,
  AMSAnalyticsEventErrorTrackDurationUpdate = 10,
  // Sending Remote Commands
  AMSAnalyticsEventErrorSendRemoteCommand = 11,
} AMSAnalyticsEvent;
