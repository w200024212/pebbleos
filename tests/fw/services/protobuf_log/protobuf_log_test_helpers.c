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

#include "protobuf_log_test_helpers.h"

#include "services/normal/protobuf_log/protobuf_log_private.h"

#include <stdint.h>
#include <stdio.h>

#define TMP_FILE "tmp_protoc_bytes"
#define TINTIN_PATH "/Users/thoffman/dev/tintin"
#define PROTO_PATH "/src/idl/nanopb"
#define PROTOC_PATH "/usr/local/bin/protoc"

void protobuf_log_test_parse_protoc(uint8_t *msg) {
  PLogMessageHdr *hdr = (PLogMessageHdr *)msg;
  FILE *file = fopen(TMP_FILE, "wb");
  fwrite(msg + sizeof(*hdr), 1, hdr->msg_size, file);
  fclose(file);

  system(PROTOC_PATH" --proto_path="TINTIN_PATH""PROTO_PATH" --decode=pebble.pipeline.Payload "
           ""TINTIN_PATH""PROTO_PATH"/payload.proto < "TMP_FILE" 2>&1");
}
