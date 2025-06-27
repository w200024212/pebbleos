#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "bf0_hal.h"
#include "board/board.h"
#include "drivers/dma.h"
#include "drivers/i2c_definitions.h"
#include "freertos_types.h"
#include "kernel/util/stop.h"
#include "os/mutex.h"
#include "register.h"

struct i2c_configuration {
  uint16_t mode;
  uint16_t addr;
  uint32_t timeout;
  uint32_t max_hz;
};

typedef struct I2CState {
  I2C_HandleTypeDef hi2c;
  DMA_HandleTypeDef hdma;
  const void *dev;
  const char *device_name;
  struct i2c_configuration i2c_conf;
  bool int_enabled;
  bool initialized;

} I2CDeviceState;

typedef const struct I2CBusHal {
  I2CDeviceState *i2c_state;
  Pinmux scl;
  Pinmux sda;
  uint8_t core;
  RCC_MODULE_TYPE module;
  IRQn_Type irqn;
  uint8_t irq_priority;
  IRQn_Type dma_irqn;
  uint8_t dma_irq_priority;
} I2CDeviceBusHal;

struct rt_i2c_msg {
  uint16_t addr;
  uint16_t mem_addr;
  uint16_t mem_addr_size;
  uint16_t flags;
  uint16_t len;
  uint8_t *buf;
};

#define RT_I2C_WR 0x0000
#define RT_I2C_RD (1u << 0)
#define RT_I2C_ADDR_10BIT (1u << 2) /* this is a ten bit chip address */
#define RT_I2C_NO_START (1u << 4)
#define RT_I2C_IGNORE_NACK (1u << 5)
#define RT_I2C_NO_READ_ACK (1u << 6) /* when I2C reading, we do not ACK */
/* read/write specified memory address,
   in this mode, no STOP condition is inserted between memory address and data */
#define RT_I2C_MEM_ACCESS (1u << 7)

#define I2C1_CORE CORE_ID_HCPU
#define I2C2_CORE CORE_ID_HCPU
#define I2C3_CORE CORE_ID_HCPU
#define I2C4_CORE CORE_ID_LCPU
#define I2C5_CORE CORE_ID_LCPU
#define I2C6_CORE CORE_ID_LCPU

void i2c_irq_handler(I2CBus *bus);
void i2c_dma_irq_handler(I2CBus *bus);
