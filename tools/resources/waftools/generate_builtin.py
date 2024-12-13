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

import generate_c_byte_array


class generate_builtin(Task.Task):
    def run(self):
        resource_ball = ResourceBall.load(self.inputs[0].abspath())
        resource_objects = [reso for reso in resource_ball.resource_objects
                            if reso.definition.storage == StorageType.builtin]

        with open(self.outputs[0].abspath(), 'w') as f:
            fw_bld_node = self.generator.bld.bldnode.find_node('src/fw')
            f.write('#include "{}"\n'.format(self.resource_id_header.path_from(fw_bld_node)))
            f.write('#include "resource/resource_storage.h"\n')
            f.write('#include "resource/resource_storage_builtin.h"\n\n')

            def var_name(reso):
                return "{}_builtin_bytes".format(reso.definition.name)

            # Write the blobs of data:
            for reso in resource_objects:
                # some resources require 8-byte aligned addresses
                # to simplify the handling we align all resources
                f.write('__attribute__ ((aligned (8)))\n')
                generate_c_byte_array.write(f, reso.data, var_name(reso))

            f.write("\n")

            f.write("const uint32_t g_num_builtin_resources = {};\n".format(len(resource_objects)))
            f.write("const BuiltInResourceData g_builtin_resources[] = {\n")

            for reso in resource_objects:
                f.write('  {{ RESOURCE_ID_{resource_id}, {var_name}, sizeof({var_name}) }},\n'
                        .format(resource_id=reso.definition.name,
                                var_name=var_name(reso)))

            f.write("};\n")


@TaskGen.feature('generate_builtin')
@TaskGen.before_method('process_source', 'process_rule')
def process_generate_builtin(self):
    task = self.create_task('generate_builtin',
                            self.resource_ball,
                            self.builtin_target)
    task.resource_id_header = self.resource_id_header
