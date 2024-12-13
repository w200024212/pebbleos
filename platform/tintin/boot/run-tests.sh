#!/bin/bash
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

set -o errexit

cd "${0%/*}"

CLAR_DIR=`cd ../../../tools/clar; pwd`

clar () {
  local test_name=${1:?}; shift;
  local test_suite=${1:?}; shift;
  local test_dir="build/test/${test_name}"

  mkdir -p "${test_dir}"

  python "${CLAR_DIR}/clar.py" \
      --file="${test_suite}" \
      --clar-path="${CLAR_DIR}" \
      "${test_dir}"

  gcc -o "${test_dir}/do_test" \
    -I"${test_dir}" -Isrc \
    -Ivendor/STM32F2xx_StdPeriph_Lib_V1.1.0/Libraries/CMSIS/Include \
    -Ivendor/STM32F2xx_StdPeriph_Lib_V1.1.0/Libraries/CMSIS/Device/ST/STM32F2xx/Include \
    -Ivendor/STM32F2xx_StdPeriph_Lib_V1.1.0/Libraries/STM32F2xx_StdPeriph_Driver/inc \
    -DMICRO_FAMILY_STM32F2 \
    -ffunction-sections \
    -Wl,-dead_strip \
    "${test_dir}/clar_main.c" "${test_suite}" $@
  # If running on a platform with GNU ld,
  # replace -Wl,-dead_strip with -Wl,--gc-sections

  echo "Running test ${test_suite}..."
  "${test_dir}/do_test"
}

clar system_flash_algo test/test_system_flash.c \
    src/drivers/stm32_common/system_flash.c
