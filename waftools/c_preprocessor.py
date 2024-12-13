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

"""
Tool that invokes the C preprocessor with any type of file.
"""


# FIXME: convert this from a rule to a task
def c_preproc(task):
    args = {
        'CC': task.generator.env.CC[0],
        'CFLAGS': ' '.join(task.generator.cflags),
        'SRC': task.inputs[0].abspath(),
        'TGT': task.outputs[0].abspath(),
    }
    return task.exec_command(
        '{CC} -E -P -c {CFLAGS} "{SRC}" -o "{TGT}"'.format(**args))


def configure(ctx):
    pass
