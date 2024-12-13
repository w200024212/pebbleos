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

#include "applib/graphics/gtypes.h"
#include "process_management/app_install_types.h"

//! @file app.h
//!
//! @addtogroup Foundation
//! @{
//!   @addtogroup App
//!   @{

//! @internal
//! Requests the app to re-render by scheduling its top window to be rendered.
void app_request_render(void);

//! @internal
//! Event loop that is shared between Rocky.js and C apps. This is called by both app_event_loop()
//! as well as rocky_event_loop_with_...().
void app_event_loop_common(void);

//! The event loop for C apps, to be used in app's main().
//! Will block until the app is ready to exit.
void app_event_loop(void);

//! @internal
//! Get the AppInstallId for the current app or worker
AppInstallId app_get_app_id(void);

//!   @} // end addtogroup App
//! @} // end addtogroup Foundation
