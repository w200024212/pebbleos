#!/bin/sh
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


run_qemu=1

while getopts "n" opt; do
    case $opt in
    n)
        # Just print out the command. Handy for mucking with qemu's command line (adding gdb/tracing).
        run_qemu=
    esac
done

qemu_bin=$PEBBLE_QEMU_BIN
if [ -z "$qemu_bin" -o ! -x $qemu_bin ]; then
    qemu_bin=$(which qemu-system-arm)
fi

if [ -z "$qemu_bin" ]; then
    echo "Could not find qemu-system arm, try putting it on your PATH or defining PEBBLE_QEMU_BIN in your environment" >&2
    exit 1
fi

qemu_cmd="$qemu_bin -cpu cortex-m3 -M stm32f2xx -nographic -monitor stdio -serial file:qemu_serial.txt -kernel build/tintin.elf -d all"
echo $qemu_cmd

if [ -n "$run_qemu" ]; then
    $qemu_cmd
    exit $?
fi
