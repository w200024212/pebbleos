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

import os.path

FUNCTION_PTR_FILE = 'pebble.auto.c'

def gen_function_pointer_array(functions):
    output = []

    # Include headers for the standard functions
    output.append('#include <stdlib.h>')
    output.append('#include <stdio.h>')
    output.append('#include <string.h>')
    output.append('')

    for f in functions:
        if not f.removed and (not f.skip_definition or f.impl_name != f.name):
            output.append('extern void %s();' % f.impl_name)

    output.append('')
    output.append('const void* const g_pbl_system_tbl[] = {')

    function_ptrs = []
    for f in functions:
        if not f.removed:
            function_ptrs.append('&%s' % f.impl_name)
        else:
            function_ptrs.append('0')

    output.extend( ('  %s,' % f for f in function_ptrs) )
    output.append('};')
    output.append('')

    return '\n'.join(output)

def make_fw_shims(functions, pbl_output_src_dir):
    with open(os.path.join(pbl_output_src_dir, 'fw', FUNCTION_PTR_FILE), 'w') as fptr_c:
        fptr_c.write(gen_function_pointer_array(functions))

