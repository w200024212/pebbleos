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

//! Memory Segments
//!
//! A memory segment is a representation of a contiguous chunk of memory.
//! Memory segments can be split, dividing the segment in two. This API
//! is designed to simplify tasks such as process loading where a chunk
//! of memory must be allocated into a bunch of smaller chunks of
//! various fixed and dynamic sizes.

#pragma once

#include <stddef.h>


typedef struct MemorySegment {
  void *start;  //!< The lowest address of the segment
  void *end;    //!< One past the highest address of the segment
} MemorySegment;


//! Returns the size of the largest object that the segment can contain.
size_t memory_segment_get_size(MemorySegment *segment);

//! Align the start pointer of a segment such that it is suitably
//! aligned for any object.
void memory_segment_align(MemorySegment *segment);

//! Split a memory segment into two.
//!
//! The child memory segment is allocated from the start of the parent,
//! and the start of the parent is moved to the end of the child.
//!
//! After the split, the start addresses of both the parent and the
//! child are guaranteed to be suitably aligned for any object.
//!
//! @param parent the memory segment to split.
//! @param child the memory segment created from the split. May be NULL.
//! @param size size of the new memory segment.
//!
//! @return start of child memory segment if successful, or NULL if
//!         there is not enough space in the parent segment to split
//!         with the requested size.
void * memory_segment_split(MemorySegment * restrict parent,
                            MemorySegment * restrict child, size_t size);
