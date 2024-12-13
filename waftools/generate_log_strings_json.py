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


import argparse
import json
from waflib import Logs

from tools.log_hashing.check_elf_log_strings import check_dict_log_strings
from tools.log_hashing.newlogging import get_log_dict_from_file

def wafrule(task):
    elf_filename = task.inputs[0].abspath()
    log_strings_json_filename = task.outputs[0].abspath()

    return generate_log_strings_json(elf_filename, log_strings_json_filename)
  

def generate_log_strings_json(elf_filename, log_strings_json_filename):
    log_dict = get_log_dict_from_file(elf_filename)
    if not log_dict:
        error = 'Unable to get log strings from {}'.format(elf_filename)
        Logs.pprint('RED', error)
        return error

    # Confirm that the log strings satisfy the rules
    output = check_dict_log_strings(log_dict)
    if output:
        Logs.pprint('RED', output)
        return 'NewLogging string formatting error'

    # Create log_strings.json 
    with open(log_strings_json_filename, "w") as json_file:
        json.dump(log_dict, json_file, indent=2, sort_keys=True)

