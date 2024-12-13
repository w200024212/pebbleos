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

import json
import os.path

DESCRIPTION_FILE = 'pebble_api.json'


# TODO: Add SDK version, defines, enums, etc.
# Only contains an ordered list of functions for now.
def gen_json_api_description(functions):
    """ Generates a json-serializable `dict` with the API description. """
    output = {
        "_pebble_api_description": {
            "file_version": 1,
        }
    }

    json_functions = []
    for f in functions:
        json_f = {
            "name": f.name,
            "deprecated": f.deprecated,
            "removed": f.removed,
            "addedRevision": f.added_revision,
        }
        json_functions.append(json_f)

    output['functions'] = json_functions
    return output


def make_json_api_description(functions, pbl_output_src_dir):
    descr_path = os.path.join(pbl_output_src_dir, 'fw', DESCRIPTION_FILE)
    with open(descr_path, 'w') as descr_file:
        json.dump(gen_json_api_description(functions),
                  descr_file,
                  sort_keys=True,
                  indent=4,
                  separators=(',', ': '))
