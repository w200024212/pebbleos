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

struct Layer;

//! Dumps debug information of the layer and all its children to debug serial
//! @param node the layer to dump
void layer_dump_tree(struct Layer* node);

//! Tries to guess the type of the layer based on the update_proc
//! @return a friendly string of the name of the layer type
const char *layer_debug_guess_type(struct Layer *layer);

//! Dumps the layer hierarchy of the top-most window to the debug serial
void command_dump_window(void);
