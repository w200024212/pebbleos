/*
 * Copyright 2024 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mfg/snowy/mfg_private.h"

#include "drivers/flash.h"
#include "flash_region/flash_region.h"
#include "mfg/snowy/snowy_boot.fpga.auto.h"
#include "util/attributes.h"

#define BOOT_FPGA_FLASH_ADDR (FLASH_REGION_MFG_INFO_BEGIN + 0x10000)

typedef struct PACKED {
  uint16_t fpga_len;
  uint16_t fpga_len_complemented;
} BootFPGAHeader;

bool mfg_info_is_boot_fpga_bitstream_written(void) {
  BootFPGAHeader header;
  flash_read_bytes((void *)&header, BOOT_FPGA_FLASH_ADDR, sizeof header);
  return (header.fpga_len != 0xffff &&
          header.fpga_len_complemented != 0xffff);
}

void mfg_info_write_boot_fpga_bitstream(void) {
  // Store the bootloader FPGA in the MFG info flash region so that the
  // bootloader can find it.
  _Static_assert(sizeof s_boot_fpga < 1<<16, "FPGA bitstream too big");
  BootFPGAHeader fpga_header = { (uint16_t)sizeof s_boot_fpga,
                                 (uint16_t)~sizeof s_boot_fpga };

  _Static_assert(
      (BOOT_FPGA_FLASH_ADDR + sizeof fpga_header + sizeof s_boot_fpga)
      < FLASH_REGION_MFG_INFO_END,
      "FPGA bitstream will overflow FLASH_REGION_MFG_INFO!");
  flash_write_bytes((const uint8_t *)&fpga_header,
                    BOOT_FPGA_FLASH_ADDR, sizeof fpga_header);
  flash_write_bytes((const uint8_t *)s_boot_fpga,
                    BOOT_FPGA_FLASH_ADDR + sizeof fpga_header,
                    sizeof s_boot_fpga);
}
