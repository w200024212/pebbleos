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

#define DISPLAY_ORIENTATION_COLUMN_MAJOR_INVERTED 0
#define DISPLAY_ORIENTATION_ROTATED_180 0
#define DISPLAY_ORIENTATION_ROW_MAJOR 1
#define DISPLAY_ORIENTATION_ROW_MAJOR_INVERTED 0

#define PBL_BW 0
#define PBL_COLOR 1

#define PBL_RECT 0
#define PBL_ROUND 1

#define PBL_DISPLAY_WIDTH 180
#define PBL_DISPLAY_HEIGHT 180

// Spalding doesn't support 2x apps, but need to define these anyways so it builds
#define LEGACY_2X_DISP_COLS DISP_COLS
#define LEGACY_2X_DISP_ROWS DISP_ROWS
#define LEGACY_3X_DISP_COLS DISP_COLS
#define LEGACY_3X_DISP_ROWS DISP_ROWS

// all pixels + 76 padding pixels before the first/after the last row
#define DISPLAY_FRAMEBUFFER_BYTES 25944

extern const void * const g_gbitmap_spalding_data_row_infos;
