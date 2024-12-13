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

typedef enum {
  //! The positive direction along the X axis goes toward the right
  //! of the watch.
  AXIS_X = 0,
  //! The positive direction along the Y axis goes toward the top
  //! of the watch.
  AXIS_Y = 1,
  //! The positive direction along the Z axis goes vertically out of
  //! the watchface.
  AXIS_Z = 2,
} IMUCoordinateAxis;
