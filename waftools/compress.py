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


def compress(task):
    cmd = ['cp', task.inputs[0].abspath(), task.inputs[0].get_bld().abspath()]
    task.exec_command(cmd)

    cmd = ['xz', '--keep', '--check=crc32', '--lzma2=dict=4KiB', task.inputs[0].get_bld().abspath()]
    task.exec_command(cmd)
