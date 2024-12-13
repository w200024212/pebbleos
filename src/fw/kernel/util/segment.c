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

#include "segment.h"

#include "system/passert.h"

#include <stdalign.h>

// Remove once the Bamboo build agents build unit tests with a more
// C11-compliant compiler (i.e. clang >= 3.5)
#if !defined(__CLANG_MAX_ALIGN_T_DEFINED) && !defined(_GCC_MAX_ALIGN_T)
typedef long double max_align_t;
#endif

static void prv_assert_sane_segment(MemorySegment *segment) {
  PBL_ASSERT(segment->start <= segment->end,
             "Segment end points before segment start");
}

static void * prv_align(void *ptr) {
  uintptr_t c = (uintptr_t)ptr;
  // Advance the pointer to the next alignment boundary.
  return (void *)((c + alignof(max_align_t) - 1) & ~(alignof(max_align_t) - 1));
}


size_t memory_segment_get_size(MemorySegment *segment) {
  prv_assert_sane_segment(segment);
  return (size_t)((uintptr_t)segment->end - (uintptr_t)segment->start);
}

void memory_segment_align(MemorySegment *segment) {
  segment->start = prv_align(segment->start);
  prv_assert_sane_segment(segment);
}

void * memory_segment_split(MemorySegment * restrict parent,
                            MemorySegment * restrict child, size_t size) {
  prv_assert_sane_segment(parent);
  char *child_start = prv_align(parent->start);
  void *child_end = child_start + size;
  if (child_end > parent->end) {
    // Requested size is too big to fit in the parent segment.
    return NULL;
  }
  void *adjusted_parent_start = prv_align(child_end);
  if (adjusted_parent_start > parent->end) {
    // The child has left no room for the adjusted parent.
    return NULL;
  }
  parent->start = adjusted_parent_start;

  if (child) {
    *child = (MemorySegment) {
      .start = child_start,
      .end = child_end,
    };
  }
  return child_start;
}
