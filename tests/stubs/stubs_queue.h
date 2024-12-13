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

#include "FreeRTOS.h"
#include "queue.h"

signed portBASE_TYPE xQueueGenericReceive( QueueHandle_t pxQueue, void * const pvBuffer, TickType_t xTicksToWait, portBASE_TYPE xJustPeeking ) {
  return pdTRUE;
}

signed portBASE_TYPE xQueueGenericSend( QueueHandle_t xQueue, const void * const pvItemToQueue, TickType_t xTicksToWait, portBASE_TYPE xCopyPosition ) {
  return pdTRUE;
}

QueueHandle_t xQueueGenericCreate( unsigned portBASE_TYPE uxQueueLength, unsigned portBASE_TYPE uxItemSize, unsigned char ucQueueType ) {
  return (void *)(intptr_t) -1;
}

void vQueueDelete( QueueHandle_t xQueue ) {
}

QueueHandle_t xQueueCreateMutex( unsigned char ucQueueType ) {
  return (QueueHandle_t)1;
}

portBASE_TYPE xQueueTakeMutexRecursive( QueueHandle_t pxMutex, TickType_t xBlockTime ) {
  return pdTRUE;
}

portBASE_TYPE xQueueGiveMutexRecursive( QueueHandle_t xMutex ) {
  return pdTRUE;
}

BaseType_t xQueueGenericReset( QueueHandle_t xQueue, BaseType_t xNewQueue ) {
  return pdTRUE;
}

