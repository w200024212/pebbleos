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

#pragma once

#include "board/board.h"
#include "drivers/dma.h"
#include "kernel/util/stop.h"

typedef struct DMAControllerState {
  int refcount;
} DMAControllerState;

typedef const struct DMAController {
  DMAControllerState *state;
  DMA_TypeDef *periph;
  uint32_t rcc_bit;
} DMAController;

typedef struct DMAStreamState {
  bool initialized;
  //! The current in-progress request (or NULL if not in progress)
  DMARequest *current_request;
} DMAStreamState;

typedef const struct DMAStream {
  DMAStreamState *state;
  DMAController *controller;
  DMA_Stream_TypeDef *periph;
  uint8_t irq_channel;
} DMAStream;

typedef enum DMARequestPriority {
  DMARequestPriority_Low = 0,
  DMARequestPriority_Medium = DMA_SxCR_PL_0,
  DMARequestPriority_High = DMA_SxCR_PL_1,
  DMARequestPriority_VeryHigh = DMA_SxCR_PL_0 | DMA_SxCR_PL_1,
} DMARequestPriority;

typedef enum DMARequestType {
  //! Transfers from one memory buffer to another (essentially a memcpy)
  DMARequestType_MemoryToMemory = DMA_SxCR_DIR_1,
  //! Transfers from a peripheral's data register to a memory buffer
  DMARequestType_PeripheralToMemory = 0,
  //! Transfers from memory buffer to a peripheral's data buffer
  DMARequestType_MemoryToPeripheral = DMA_SxCR_DIR_0,
} DMARequestType;

typedef enum DMARequestDataSize {
  DMARequestDataSize_Byte = 0,
  DMARequestDataSize_HalfWord = DMA_SxCR_MSIZE_0 | DMA_SxCR_PSIZE_0,
  DMARequestDataSize_Word = DMA_SxCR_MSIZE_1 | DMA_SxCR_PSIZE_1,
} DMARequestDataSize;

typedef enum DMARequestTransferType {
  DMARequestTransferType_None = 0,
  DMARequestTransferType_Direct,
  DMARequestTransferType_Circular,
} DMARequestTransferType;

typedef struct DMARequestState {
  bool initialized;
  //! The type of request currently in-progress
  DMARequestTransferType transfer_type;
  //! The destination and length of the current transfer
  void *transfer_dst;
  uint32_t transfer_length;
  //! The handler for transfer events
  union {
    DMADirectRequestHandler direct_transfer_handler;
    DMACircularRequestHandler circular_transfer_handler;
  };
  void *context;
} DMARequestState;

typedef const struct DMARequest {
  DMARequestState *state;
  DMAStream *stream;
  uint32_t channel;
  uint32_t irq_priority;
  DMARequestPriority priority;
  DMARequestType type;
  DMARequestDataSize data_size;
} DMARequest;


void dma_stream_irq_handler(DMAStream *this);
