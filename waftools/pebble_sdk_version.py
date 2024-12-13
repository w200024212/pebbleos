#!/usr/bin/env python
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


def set_env_sdk_version(self, process_info_node):
    with open(process_info_node.abspath(), 'r') as f:
        for line in f:
            if "PROCESS_INFO_CURRENT_SDK_VERSION_MAJOR" in line:
                self.env.SDK_VERSION_MAJOR = int(line.split(' ')[2].rstrip(), 16)
            if "PROCESS_INFO_CURRENT_SDK_VERSION_MINOR" in line:
                self.env.SDK_VERSION_MINOR = int(line.split(' ')[2].rstrip(), 16)
    return
