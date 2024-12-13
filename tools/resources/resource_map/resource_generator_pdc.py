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

from resources.types.resource_object import ResourceObject
from resources.resource_map.resource_generator import ResourceGenerator

from tools.generate_pdcs import pdc_gen

import os


class ResourceGeneratorPdc(ResourceGenerator):
    type = 'pdc'

    @staticmethod
    def definitions_from_dict(bld, definition_dict, resource_source_path):
        definitions = ResourceGenerator.definitions_from_dict(bld, definition_dict,
                                                              resource_source_path)

        source_root = bld.path.make_node('.')

        for d in definitions:
            node = bld.path.find_node(d.file)

            # PDCS (animated vectors) are described as a folder path. Adjust the sources so if any
            # frame in the animation changes we regenerate the pdcs
            if os.path.isdir(node.abspath()):
                source_nodes = bld.path.find_node(d.file).ant_glob("*.svg")
                d.sources = [n.path_from(source_root) for n in source_nodes]

        return definitions

    @staticmethod
    def generate_object(task, definition):
        node = task.generator.path.make_node(definition.file)

        if os.path.isdir(node.abspath()):
            output, errors = pdc_gen.create_pdc_data_from_path(
                    node.abspath(),
                    viewbox_size=(0, 0),
                    verbose=False,
                    duration=33,
                    play_count=1,
                    precise=False)
        else:
            output, errors = pdc_gen.create_pdc_data_from_path(
                    task.inputs[0].abspath(),
                    viewbox_size=(0, 0),
                    verbose=False,
                    duration=0,
                    play_count=0,
                    precise=True)

        return ResourceObject(definition, output)
