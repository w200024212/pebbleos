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

#include "layer.h"

Layer *__layer_tree_traverse_next__test_accessor(Layer *stack[],
    int const max_depth, uint8_t *current_depth, const bool descend);

typedef bool (*LayerIteratorFunc)(Layer *layer, void *ctx);

void layer_process_tree(Layer *node, void *ctx, LayerIteratorFunc iterator_func);
