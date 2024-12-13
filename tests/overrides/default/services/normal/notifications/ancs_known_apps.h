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

// @nolint
// please don't change these values manually, they are derived from the spreadsheet
// "Notification Colors"

#if PLATFORM_TINTIN
// Tintin does not have the color arg in its App Metadata. Remove it.
#define APP(id, icon, color) { id, icon }
#else
#define APP(id, icon, color) { id, icon, color }
#endif
    APP(IOS_SMS_APP_ID, TIMELINE_RESOURCE_GENERIC_SMS, GColorIslamicGreenARGB8),

#undef APP
