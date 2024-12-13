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


static uint8_t s_test_transcription_example[] = {

  // Transcription
  0x01,         // Transcription type
  0x02,         // Sentence count

  // Sentence #1
  0x02, 0x00,   // Word count

  // Word #1
  85,           // Confidence
  0x05, 0x00,   // Word length
  'H', 'e', 'l', 'l', 'o',

  // Word #2
  74,           // Confidence
  0x08, 0x00,   // Word length
  'c', 'o', 'm', 'p', 'u', 't', 'e', 'r',

  // Sentence #2
  0x03, 0x00,   // Word count

  // Word #1
  13,           // Confidence
  0x04, 0x00,   // Word length
  'h', 'e', 'l', 'l',

  // Word #1
  3,           // Confidence
  0x02, 0x00,   // Word length
  'o', 'h',

  // Word #2
  0,           // Confidence
  0x07, 0x00,   // Word length
  'c', 'o', 'm', 'p', 'u', 't', 'a',
};

