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

#include <inttypes.h>

#include "syscall/syscall_internal.h"
#include "system/profiler.h"

#define CMSIS_COMPATIBLE
#include <mcu.h>


// ------------------------------------------------------------------------------------
// Find node by ptr
static bool prv_ptr_list_filter(ListNode* list_node, void* data) {
  ProfilerNode* node = (ProfilerNode*)list_node;
  return (node == data);
}


ProfilerNode *prv_find_node(ProfilerNode *find_node) {
  ListNode* node = list_find(g_profiler.nodes, prv_ptr_list_filter, (void*)find_node);

  return (ProfilerNode *)node;
}

DEFINE_SYSCALL(void, sys_profiler_init, void) {
  profiler_init();
}

DEFINE_SYSCALL(void, sys_profiler_start, void) {
  profiler_start();
}

DEFINE_SYSCALL(void, sys_profiler_stop, void) {
  profiler_stop();
}

DEFINE_SYSCALL(void, sys_profiler_print_stats, void) {
  profiler_print_stats();
}

DEFINE_SYSCALL(void, sys_profiler_node_start, ProfilerNode *node) {
  if (PRIVILEGE_WAS_ELEVATED) {
    if (!list_contains(g_profiler.nodes, (ListNode *)node)) {
      // Instead of calling syscall_failed(), simply return. If PROFILE_INIT has not been
      // executed yet, there won't be any nodes in the list.
      return;
    }
  }

  node->start = DWT->CYCCNT;
}

DEFINE_SYSCALL(void, sys_profiler_node_stop, ProfilerNode *node) {

  // Capture the cycle count as soon as possible, before we validate the node argument
  uint32_t dwt_cyc_cnt = DWT->CYCCNT;

  if (PRIVILEGE_WAS_ELEVATED) {
    if (!list_contains(g_profiler.nodes, (ListNode *)node)) {
      // Instead of calling syscall_failed(), simply return. If PROFILE_INIT has not been
      // executed yet, there won't be any nodes in the list.
      return;
    }
  }

  profiler_node_stop(node, dwt_cyc_cnt);
}
