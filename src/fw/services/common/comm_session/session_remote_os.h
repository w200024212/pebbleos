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
  RemoteBitmaskOS = 0x7, // bits 0 - 2
} RemoteBitmask;

typedef enum {
  RemoteOSUnknown = 0,
  RemoteOSiOS = 1,
  RemoteOSAndroid = 2,
  RemoteOSX = 3,
  RemoteOSLinux = 4,
  RemoteOSWindows = 5,
} RemoteOS;
