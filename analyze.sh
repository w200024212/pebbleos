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


# A couple of clangs checkers we may be interested in
BUILTIN_CHECKERS=core,alpha.deadcode,alpha.security
# Get an array of all the checkers in the checkers/build folder
PLUGINS_PATH="`pwd`/checkers/build"
PLUGINS=(`find $PLUGINS_PATH -name '*.dylib'`)
# Convert the array to a comma-separated string of checker names
PEBBLE_CHECKERS=
LOAD_ARGS=
for PLUGIN in "${PLUGINS[@]}"
do
  # <checker>.dylib -> pebble.<checker>
  CHECKER="pebble.`basename $PLUGIN .dylib`"
  PEBBLE_CHECKERS="$PEBBLE_CHECKERS,$CHECKER"
  LOAD_ARGS="$LOAD_ARGS -load-plugin $PLUGIN"
  echo "Loading $CHECKER"
done

PYTHON=python
if hash pypy 2>/dev/null
then
  PYTHON=pypy
fi

# Run scan-build.
# Firmware is configured without log hashing since it is currently broken with clang, and we skip the final link step. We also
# build with LTO since this allows clang to skip the code gen phase and somewhat speed up the analysis.
scan-build $LOAD_ARGS -enable-checker "$BUILTIN_CHECKERS$PEBBLE_CHECKERS" $PYTHON waf distclean configure --use_env_cc --lto --no-link --nohash --board=snowy_bb2 build
