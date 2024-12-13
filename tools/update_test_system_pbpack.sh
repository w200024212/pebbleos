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


# NOTE: Ensure that you have the correct version of FreeType installed before building the firmware
# and running this script! Otherwise the kerning of our font files will change and unit tests will
# fail on checking images. You can get it by running:
# brew uninstall --force freetype
# brew update
# brew install pebble/pebble-fw/freetype

# NOTE: If updating for snowy (the default unit test platform), you must duplicate the GOTHIC_18
# stanza in resource/normal/base/resource_map.json, change the name to GOTHIC_18_COMPRESSED, and add
# the field: "compress": "RLE4" before building the firmware and running this script. Otherwise the
# unit tests in `test_text_resources.c` will fail. Of course, revert adding the GOTHIC_18_COMPRESSED
# stanza in the resource map before committing.

# NOTE: Ensure that you DO NOT build the firmware with `--qemu` before running this script!

# This script helps with updating tests/fixtures/resources/system_resources.pbpack.
# Once your build has completed, execute this script with the argument of the platform you built for
# (e.g. "snowy", "silk", etc.) to copy your built system_resource.pbpack to the test tree, along
# with all of the other required resource ID files.

# Get the location of the Tintin tree
pushd `dirname $0` > /dev/null
BASEPATH=`pwd -P`/..
popd > /dev/null

if [ "$1" == "-h" ] || [ "$1" == "" ]; then
    echo "Usage: `basename $0` PLATFORM"
    exit 0
fi

PLATFORM="$1"
SRC="$BASEPATH/build/src/fw/resource"
FIXTURES="$BASEPATH/tests/fixtures/resources"
OVERRIDES="$BASEPATH/tests/overrides/default/resources/$PLATFORM/resource"

mkdir -p "$OVERRIDES"
cp -v "$SRC/timeline_resource_ids.auto.h" "$OVERRIDES"
cp -v "$SRC/resource_version.auto.h" "$OVERRIDES"
cp -v "$SRC/resource_ids.auto.h" "$OVERRIDES"

cp -v "$BASEPATH/build/system_resources.pbpack" "$FIXTURES/system_resources_$PLATFORM.pbpack"

# Only update these fixtures if the firmware was built for snowy
if [ "$1" == "snowy" ]; then
    cp -v "$BASEPATH/build/src/fw/builtin_resources.auto.c" "$FIXTURES"
    cp -v "$SRC/timeline_resource_table.auto.c" "$FIXTURES"
    cp -v "$SRC/pfs_resource_table.auto.c" "$FIXTURES/pfs_resource_table.c"
fi
