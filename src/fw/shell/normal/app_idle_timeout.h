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

//! Start using the idle timeout for the current app.
void app_idle_timeout_start(void);

//! Stop using the idle timeout for the current app. This is safe to call even if the idle timeout wasn't running.
void app_idle_timeout_stop(void);

//! Pause the idle timeout for the current app. This is safe to call even if the idle timeout wasn't running
//! previously.
void app_idle_timeout_pause(void);

//! Resume the idle timeout for the current app. This is safe to call even if the idle timeout wasn't running
//! previously.
void app_idle_timeout_resume(void);

//! Reset the timeout. Call this whenever there is activity that should prevent the idle timeout from firing. This
//! is safe to call even if the idle timeout wasn't running previously.
void app_idle_timeout_refresh(void);

