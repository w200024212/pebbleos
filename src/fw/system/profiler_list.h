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

// List of specific node timers. These are started and stopped using PROFILER_NODE_START
// and PROFILER_NODE_STOP
PROFILER_NODE(mic)
PROFILER_NODE(framebuffer_dma)
PROFILER_NODE(render_modal)
PROFILER_NODE(render_app)
PROFILER_NODE(dirty_rect)
PROFILER_NODE(gfx_test_update_proc)
PROFILER_NODE(voice_encode)
PROFILER_NODE(compositor)
PROFILER_NODE(hrm_handling)
PROFILER_NODE(display_transfer)
PROFILER_NODE(text_render_flash)
PROFILER_NODE(text_render_compress)
