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

#include <inttypes.h>
#include <stdbool.h>

#include "services/common/get_bytes/get_bytes.h"

typedef enum {
  GetBytesStorageTypeUnknown,
  GetBytesStorageTypeCoredump,
  GetBytesStorageTypeFile,
  GetBytesStorageTypeFlash
} GetBytesStorageType;

struct GetBytesStorageImplementation;
typedef struct GetBytesStorageImplementation GetBytesStorageImplementation;

typedef struct {
  // A struct full of function pointers that implements a storage API
  const GetBytesStorageImplementation *impl;

  //! A void pointer that the GetBytesStorageImplementation is free to stash stuff into
  void *impl_data;

  //! The offset into the storage we've initialized. Updated by pb_storage_append. pb_storage_init
  //! may set this to a non-zero value.
  uint32_t current_offset;
} GetBytesStorage;

// info used by the setup routines depending on the implementation
typedef struct {
  //! Used by GetBytesStorageTypeFile
  char *filename;
  //! Used by GetBytesStorageTypeFlash
  uint32_t flash_start_addr;
  uint32_t flash_len;
  //! Used by GetBytesStorageTypeCoredump
  bool only_get_new_coredump;
} GetBytesStorageInfo;

//! Set up the storage. This may include allocating memory, open a file descriptor, etc.
bool gb_storage_setup(GetBytesStorage *storage, GetBytesObjectType object_type,
                     GetBytesStorageInfo *info);

//! Retrieve the size of the object that is to be sent
GetBytesInfoErrorCode gb_storage_get_size(GetBytesStorage *storage, uint32_t *size);

//! Read a chunk of the object into a buffer
bool gb_storage_read_next_chunk(GetBytesStorage *storage, uint8_t *buffer, uint32_t len);

//! Cleanup the storage.
void gb_storage_cleanup(GetBytesStorage *storage, bool successful);
