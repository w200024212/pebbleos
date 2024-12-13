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

//! @file app_custom_icon.h
//! This file is part of app_install_manager.c
//! It provides a Pebble protocol endpoint to allow 3rd party apps
//! to customize the title and icon of certain stock apps, like the "Sports" app.

#include "pebble_process_md.h"
#include "applib/graphics/gtypes.h"
#include "process_management/app_install_types.h"

const char *app_custom_get_title(AppInstallId app_id);

const GBitmap *app_custom_get_icon(AppInstallId app_id);
