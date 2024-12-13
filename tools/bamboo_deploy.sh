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

# Usage:
# bamboo_deploy.sh environment commit [staging?]
# e.g. bamboo_deploy.sh porksmoothie v3.10-beta2
# e.g. bamboo_deploy.sh release-v3.8 v3.10 1

bucket=pebblefw
if [ "$3" = "1" ]; then
    bucket=$bucket-staging
fi
stage=$1
notes="build/firmware/release-notes.txt"

cd tintin && git checkout $2 && cd ../

files=$(ls build/firmware/*.pbz)
if [ "$files" = "" ]; then
	echo 'No .pbz files found'
	exit 1
fi
for bundle in $files; do
    python tintin/tools/deploy_pbz_to_pebblefw.py \
        --bucket $bucket \
        --stage $stage \
        --notes $notes \
        $bundle
done
