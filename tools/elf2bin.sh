#!/bin/bash
# Copyright 2024 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


USAGE="Usage: $0 ELF_FILE"

if [ "$#" == "0" ]; then
    echo "$USAGE"
    exit 1
fi

IN_FILE=$1
IN_FILE_BASE=$(basename "$IN_FILE")
MODE=binary
OUT_FILE=$(pwd)/$(echo "$IN_FILE_BASE" | sed 's/elf/bin/')

arm-none-eabi-objcopy -O $MODE $IN_FILE $OUT_FILE
