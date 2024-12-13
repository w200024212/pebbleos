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


from __future__ import with_statement
import base64, zlib, re, sys

def compress_file(filename):
    with open(filename) as f:
        contents = f.read()

    if sys.version_info >= (3, 0):
        bin = zlib.compress(bytes(contents, 'utf-8'))
        return ('"%s" : r"""' % filename) + base64.b64encode(bin).decode('utf-8') + '"""'
    else:
        bin = zlib.compress(contents)
        return ('"%s" : r"""' % filename) + base64.b64encode(bin) + '"""'

def decompress_file(content):
    return zlib.decompress(base64.b64decode(content))

def build_table(filenames):
    table = "\n\nCLAR_FILES = {\n"
    table += ",\n".join(compress_file(f) for f in filenames)
    table += "\n}"
    return table

CLAR_FOOTER = """
if __name__ == '__main__':
    main()
"""

if __name__ == '__main__':
    clar_table = build_table([
        'clar.c',
        'clar_print_default.c',
        'clar_print_tap.c',
        'clar_sandbox.c',
        'clar_fixtures.c',
        'clar_mock.c',
        'clar_fs.c',
        'clar_categorize.c',
        'clar.h'
    ])

    with open('_clar.py') as f:
        clar_source = f.read()

    with open('clar.py', 'w') as f:
        f.write(clar_source)
        f.write(clar_table)
        f.write(CLAR_FOOTER)
