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

from waflib import Node, Task, TaskGen

from resources.types.resource_ball import ResourceBall
from resources.types.resource_definition import StorageType

from pbpack import ResourcePack


class generate_pbpack(Task.Task):
    def run(self):
        resource_ball = ResourceBall.load(self.inputs[0].abspath())
        resource_objects = [reso for reso in resource_ball.resource_objects
                            if reso.definition.storage == StorageType.pbpack]

        pack = ResourcePack(self.is_system)

        for r in resource_objects:
            pack.add_resource(r.data)

        with open(self.outputs[0].abspath(), 'wb') as f:
            pack.serialize(f)


@TaskGen.feature('generate_pbpack')
@TaskGen.before_method('process_source', 'process_rule')
def process_generate_pbpack(self):
    task = self.create_task('generate_pbpack',
                            self.resource_ball,
                            self.pbpack_target)
    task.is_system = getattr(self, 'is_system', False)
