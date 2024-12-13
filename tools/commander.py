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
import logging
import sys

import commander

if __name__ == '__main__':
    def reattach_handler(logger, formatter, handler):
        if handler is not None:
            logger.removeHandler(handler)
        handler = logging.StreamHandler(sys.stdout)
        handler.setFormatter(formatter)
        logger.addHandler(handler)
        return handler

    parser = argparse.ArgumentParser(description='Pebble Commander.')
    parser.add_argument('-v', '--verbose', help='verbose logging', action='count',
                        default=0)
    parser.add_argument('-t', '--tty', help='serial port (defaults to auto-detect)', metavar='TTY',
                        default=None)
    parser.add_argument('dict', help='log-hashing dictionary file', metavar='loghash_dict.json',
                        nargs='?', default=None)

    args = parser.parse_args()

    log_level = (logging.DEBUG if args.verbose >= 2
                 else logging.INFO if args.verbose >= 1
                 else logging.WARNING)

    use_colors = True
    formatter_string = '%(name)-12s: %(levelname)-8s %(message)s'
    if use_colors:
        formatter_string = '\x1b[33m%s\x1b[m' % formatter_string

    formatter = logging.Formatter(formatter_string)
    handler = reattach_handler(logging.getLogger(), formatter, None)
    logging.getLogger().setLevel(log_level)

    with commander.InteractivePebbleCommander(
            loghash_path=args.dict, tty=args.tty) as cmdr:
        cmdr.attach_prompt_toolkit()
        # Re-create the logging handler to use the patched stdout
        handler = reattach_handler(logging.getLogger(), formatter, handler)
        cmdr.command_loop()
