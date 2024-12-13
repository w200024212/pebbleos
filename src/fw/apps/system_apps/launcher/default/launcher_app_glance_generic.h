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

#include "launcher_app_glance.h"

#include "applib/ui/kino/kino_reel.h"
#include "process_management/app_menu_data_source.h"
#include "services/normal/timeline/timeline_resources.h"

#define LAUNCHER_APP_GLANCE_GENERIC_ICON_SIZE_TYPE (TimelineResourceSizeTiny)

//! Create a generic launcher app glance for the provided app menu node.
//! @param node The node that the new generic glance should represent
//! @param fallback_icon A long-lived fallback icon to use if no other icons are available; will
//! not be destroyed when the generic glance is destroyed
//! @param fallback_icon_resource_id The resource ID of the fallback icon
LauncherAppGlance *launcher_app_glance_generic_create(const AppMenuNode *node,
                                                      const KinoReel *fallback_icon,
                                                      uint32_t fallback_icon_resource_id);
