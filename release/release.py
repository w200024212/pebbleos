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


from __future__ import print_function

import argparse
import json
import os
import re
import sh
import shutil
import sys
import tempfile

def prepare_staging_directory(board_type, git_tag):
    temp_path = tempfile.mkdtemp('tintin')
    artifacts_root = os.path.join(temp_path, 'pebble_{}_{}'.format(board_type, git_tag))
    os.mkdir(artifacts_root)
    return artifacts_root

def waf_build(root, board, cflags, is_release=True):
    waf_env = os.environ.copy()
    waf_env["CFLAGS"] = ' '.join(cflags)
    waf = sh.Command('{}/waf'.format(root))

    sh.cd(root)
    waf.distclean()
    try:
        waf.configure(release=is_release, jtag='olimex', board=board, _env = waf_env)
    except sh.ErrorReturnCode_1, e:
        print(e.stderr)
    for target in ('build', 'build_safe'):
        waf(target, _env = waf_env)

def waf_cleanup(root):
    sh.cd(root)
    waf.distclean()

def copy_files(root, staging, files, tag):
    for f in files:
        s = os.path.join(root, f['src'])
        d = os.path.join(staging, f['dst'].format(tag=tag))

        if not os.path.isfile(s):
            raise Exception("File '{}' does not exist".format(s))

        dest_dir = os.path.dirname(d)
        if not os.path.isdir(dest_dir):
            os.makedirs(dest_dir)

        shutil.copyfile(s, d)

def do_release(root, recipe, no_build):
    print('releasing {}...'.format(recipe['name']))

    fw_params = recipe['firmware']
    for board in recipe['firmware']['boards']:
        sh.cd(root)
        tag = sh.git.describe().strip()

        dest_dir = prepare_staging_directory(board, tag)
        outfile = '/tmp/pebble_fw_{}_{}'.format(board, tag)
        outfile_format = 'zip'
        archive_file = outfile + '.' + outfile_format

        if os.path.exists(archive_file):
            print('Deleted old archive {}'.format(archive_file))
            os.remove(archive_file)

        if not no_build:
            print('building')
            waf_build(root,
                      board = board,
                      cflags = fw_params['cflags'],
                      is_release = fw_params['release'])

        print('copying files')
        copy_files(root, dest_dir, recipe['files'], tag)

        print('archiving')
        shutil.make_archive(outfile, outfile_format, dest_dir)

        print('created release archive')
        print(outfile + '.' + outfile_format)
        print()

    print('release complete')


def main():
    if 'TINTIN_HOME' not in os.environ:
        raise Exception('\'TINTIN_HOME\' is must be defined')

    tintin_root = os.path.abspath(os.path.expanduser(os.environ['TINTIN_HOME']))
    if not os.path.isdir(tintin_root):
        raise Exception('TINTIN_HOME points to invalid directory \'{}\''.format(tintin_root))

    parser = argparse.ArgumentParser()
    parser.add_argument('release_recipe')
    parser.add_argument('-v', '--verbose', action='store_true')
    parser.add_argument('-s', '--summary', action='store_true')
    parser.add_argument('--no-build', action='store_true')
    args = parser.parse_args()

    with open(args.release_recipe, 'r') as f:
        recipe = json.load(f)
    do_release(tintin_root, recipe, args.no_build)

if __name__ == '__main__':
    main()
