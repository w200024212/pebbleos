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

#include "pb.h"

typedef struct PLogPackedVarintsEncoderArg {
  uint16_t num_values;
  uint32_t *values;
} PLogPackedVarintsEncoderArg;

typedef struct PLogTypesEncoderArg {
  uint16_t num_types;
  ProtobufLogMeasurementType *types;
} PLogTypesEncoderArg;

typedef struct PLogBufferEncoderArg {
  uint16_t len;
  uint8_t *buffer;
} PLogBufferEncoderArg;

// -----------------------------------------------------------------------------------------
// Callback used to stuff in the uuid
bool protobuf_log_util_encode_uuid(pb_ostream_t *stream, const pb_field_t *field,
                                  void * const *arg);

// -----------------------------------------------------------------------------------------
// Callback used to stuff in a string
bool protobuf_log_util_encode_string(pb_ostream_t *stream, const pb_field_t *field,
                                    void * const *arg);

// -----------------------------------------------------------------------------------------
// Callback used to stuff in a packed array of varints
bool protobuf_log_util_encode_packed_varints(pb_ostream_t *stream, const pb_field_t *field,
                                            void * const *arg);

// -----------------------------------------------------------------------------------------
// Callback used to stuff in the array of types
bool protobuf_log_util_encode_measurement_types(pb_ostream_t *stream, const pb_field_t *field,
                                               void * const *arg);

// -----------------------------------------------------------------------------------------
// Callback used to stuff in a data buffer. Useful for MeasurementSets or Events
bool protobuf_log_util_encode_buffer(pb_ostream_t *stream, const pb_field_t *field,
                                    void * const *arg);
