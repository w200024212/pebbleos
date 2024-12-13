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

// If a ping is due to be sent, send it. This should be called when we are already sending other
// data to the phone anyways in order to minimize the number of times we have to wake up the phone.
// It will return without doing anything if a minimum amount of time (currently 1 hour)
// has not elapsed since the last ping was sent out.
void ping_send_if_due(void);
