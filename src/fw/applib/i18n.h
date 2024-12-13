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

#include <stddef.h>

//! @file i18n.h
//! Wrapper function for i18n syscalls that make up the app's i18n APIs

//! @addtogroup Foundation
//! @{
//!   @addtogroup Internationalization
//! \brief Internationalization & Localization APIs
//!
//!   @{

//! Get the ISO locale name for the language currently set on the watch
//! @return A string containing the ISO locale name (e.g. "fr", "en_US", ...)
//! @note It is possible for the locale to change while your app is running.
//! And thus, two calls to i18n_get_system_locale may return different values.
const char *app_get_system_locale(void);

//! @internal
//! Get a translated version of a astring in a given locale
//! @param locale the ISO locale to translate to
//! @param string the english string to translate
//! @param buffer the buffer to copy the translation to
//! @param length the length of the buffer
void app_i18n_get(const char *locale, const char *string, char *buffer, size_t length);

//!   @} // end addtogroup Internationalization
//! @} // end addtogroup Foundation
