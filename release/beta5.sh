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


# check for prerequisites
if ! which srec_cat > /dev/null; then echo "Error! srec_cat is not installed" >&2; exit 1; fi

echo "(╯°□°）╯︵ ┻━┻"
echo "Building beta5..."

TINTIN_HOME="$(dirname $0)/.."

RELEASE_NAME=beta5
BOARDS=('ev2_4' 'v1_5' 'v2_0')
cd $TINTIN_HOME

FW_VERSION=$(git describe)

for BOARD in "${BOARDS[@]}"
do
    DIST_DIR=$TINTIN_HOME/dist/beta5/$BOARD

    rm -rf $DIST_DIR
    mkdir -p $DIST_DIR/mfg

    echo "Building target: $BOARD"

    ./waf distclean &&
    ./waf configure --board=$BOARD --release &&
    ./waf -p clean build bundle &&
    cp build/src/boot/tintin_boot.elf $DIST_DIR/$BOARD-$FW_VERSION-boot.elf &&
    cp build/src/fw/tintin_fw.elf $DIST_DIR/$BOARD-$FW_VERSION-fw.elf &&
    cp build/system_resources.pbpack $DIST_DIR/$BOARD-$FW_VERSION-resources.pbpack &&
    cp build/*normal_$BOARD*.pbz $DIST_DIR/ &&
    cp build/system_resources.pbpack $DIST_DIR/mfg/$BOARD-$FW_VERSION-resources.pbpack &&
    srec_cat build/src/boot/tintin_boot.hex -intel build/src/fw/tintin_fw.hex -intel -o $DIST_DIR/mfg/$BOARD-$FW_VERSION-boot-fw.hex -intel -Output_Block_Size=16

    if [[ $? -ne 0 ]]; then
        echo "release failed"
        exit;
    fi
done

echo "ok"

