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


echo "The script you are running ${BASH_SOURCE[0]}"
PBI2PNG_SH=${BASH_SOURCE[0]}
PATH_TO_PBI2PNG=$(echo "$PBI2PNG_SH" | sed 's/\.sh/\.py/')
FILES=*.pbi
for file in $FILES
do
  outfile=$(pwd)/$(echo "$file" | sed 's/\.pbi/\.png/')
  python "$PATH_TO_PBI2PNG" "$file" "$outfile"
done

