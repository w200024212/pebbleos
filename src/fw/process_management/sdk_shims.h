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

struct GContext;
typedef struct GContext GContext;

//! @addtogroup Foundation
//! @{
//!   @addtogroup App
//!   @{

//! Gets the graphics context that belongs to the caller of the function.
//! @note Only use the returned GContext inside a drawing callback (`update_proc`)!
//! @return The current graphics context
//! @see \ref Drawing
//! @see \ref LayerUpdateProc

GContext* app_get_current_graphics_context(void);

//!   @} // end addtogroup App
//! @} // end addtogroup Foundation

