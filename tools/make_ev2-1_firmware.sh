#!/bin/sh
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


if [ -z "$TINTIN_HOME" ]; then
    echo "TINTIN_HOME must be set";
    exit -1;
fi

STAGING_AREA=`mktemp -d -t pebble`
FW_DIR=$STAGING_AREA/pebble_ev2-1_firmware
DIST_DIR=$TINTIN_HOME/dist

mkdir -p $DIST_DIR
mkdir -p $FW_DIR

cd $TINTIN_HOME

echo "Building targets..."

./waf distclean
./waf configure --board=ev2 -d
./waf clean build build_safe

echo "Bundling release..."

cp release-notes/pebble_ev2-1_firmware.txt $FW_DIR/README
cp build/src/boot/tintin_boot.hex $FW_DIR/pebble_ev2-1_boot.hex
cp build/safe/src/fw/tintin_fw.hex $FW_DIR/pebble_ev2-1_fw.hex

cd $FW_DIR
md5 pebble_ev2-1_fw.hex > pebble_ev2-1_fw.md5
md5 pebble_ev2-1_boot.hex > pebble_ev2-1_boot.md5

echo "Compressing..."

cd $STAGING_AREA && zip -r $DIST_DIR/`date +"%s"`_pebble_ev2-1_firmware.zip pebble_ev2-1_firmware

echo "Complete!"
