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


echo "(╯°□°）╯︵ ┻━┻"
echo "Building In-N-Out..."

if [ -z "$TINTIN_HOME" ]; then
    echo "TINTIN_HOME must be set";
    exit -1;
fi

RELEASE_NAME=ino
BOARD=ev2_4
DIST_DIR=$TINTIN_HOME/dist/in-n-out/$BOARD

rm -rf $DIST_DIR
mkdir -p $DIST_DIR

cd $TINTIN_HOME

SHORT_HASH=$(git rev-parse --short HEAD)

echo "Building targets..."

./waf distclean &&
./waf configure --board=$BOARD --release &&
./waf -p clean build build_safe bundle bundle_safe &&
cp build/src/boot/tintin_boot.elf $DIST_DIR/$BOARD-$SHORT_HASH-boot.elf && 
cp build/src/fw/tintin_fw.elf $DIST_DIR/$BOARD-$SHORT_HASH-fw.elf && 
cp build/safe/src/fw/tintin_fw.elf $DIST_DIR/$BOARD-$SHORT_HASH-recovery.elf &&
cp build/system_resources.pbpack $DIST_DIR/$BOARD-$SHORT_HASH-resources.pbpack && 
cp build/*normal_ev2_4*.pbz $DIST_DIR/ && cp build/*recovery_ev2_4*.pbz $DIST_DIR/

if [[ $? -ne 0 ]]; then
    echo "release failed"
    exit;
fi

echo "ok"

