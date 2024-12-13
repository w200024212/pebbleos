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

#include <stdint.h>
#include <stdbool.h>

typedef uint32_t Codepoint;

#define EM_DASH "—"
#define EN_DASH "–"

#define ELLIPSIS_CODEPOINT 0x2026
#define HYPHEN_CODEPOINT 0x002D
#define MINUS_SIGN_CODEPOINT 0x2212
#define SPACE_CODEPOINT ' '
#define NEWLINE_CODEPOINT '\n'
#define NULL_CODEPOINT '\0'
#define ZERO_WIDTH_SPACE_CODEPOINT 0x200B
#define WORD_JOINER_CODEPOINT 0x2060

bool codepoint_is_formatting_indicator(const Codepoint codepoint);

bool codepoint_is_skin_tone_modifier(const Codepoint codepoint);

bool codepoint_is_end_of_word(const Codepoint codepoint);

bool codepoint_is_ideograph(const Codepoint codepoint);

bool codepoint_should_skip(const Codepoint codepoint);

bool codepoint_is_zero_width(const Codepoint codepoint);

bool codepoint_is_latin(const Codepoint codepoint);

bool codepoint_is_emoji(const Codepoint codepoint);

// This is a least dirty hack to enable special rendering when a special codepoint is hit in the
// text being rendered
bool codepoint_is_special(const Codepoint codepoint);
