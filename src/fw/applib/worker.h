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

//! @file worker.h
//!
//! @addtogroup Foundation
//! @{
//!   @addtogroup Worker
//!   @{

//! The event loop for workers, to be used in worker's main(). Will block until the worker is ready to exit.
//! @see \ref App
void worker_event_loop(void);

//! Launch the foreground app for this worker
void worker_launch_app(void);

//!   @} // end addtogroup Worker
//! @} // end addtogroup Foundation

