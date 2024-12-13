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

#if BT_CONTROLLER_DA14681
// Larger MTU sizes appear to have a more considerable impact on throughput than one would expect
// (theoretical gain from 158 bytes - 512 bytes should only be ~3% but we are seeing up to ~30%
// bumps).  More investigation needs to be done to understand exactly why. For now, let's bump the
// size so Android phones which support large MTUs can leverage it
#define ATT_MAX_SUPPORTED_MTU (339)
#else
// It's 158 bytes now because that's the maximum payload iOS 8 allows.
// On legacy products, only iOS uses LE so stick with this max buffer size
#define ATT_MAX_SUPPORTED_MTU (158)
#endif
