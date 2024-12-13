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

#include <stdint.h>

//! @file preferred_durations.h
//! @addtogroup UI
//! @{
//!   @addtogroup Preferences
//!
//! \brief Values recommended by the system
//!
//!   @{

//! Get the recommended amount of milliseconds a result window should be visible before it should
//! automatically close.
//! @note It is the application developer's responsibility to automatically close a result window.
//! @return The recommended result window timeout duration in milliseconds
uint32_t preferred_result_display_duration(void);

//!   @} // end addtogroup Preferences
//! @} // end addtogroup UI
