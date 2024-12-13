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

#include "launcher_app_glance.h"

#include "applib/ui/kino/kino_reel_custom.h"
#include "system/passert.h"
#include "util/struct.h"

GSize launcher_app_glance_get_size_for_reel(KinoReel *reel) {
  PBL_ASSERTN(reel->impl && (reel->impl->reel_type == KinoReelTypeCustom));
  LauncherAppGlance *glance = kino_reel_custom_get_data(reel);
  return NULL_SAFE_FIELD_ACCESS(glance, size, GSizeZero);
}
