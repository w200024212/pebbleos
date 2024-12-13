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

#include "action_menu_hierarchy.h"
#include "action_menu_layer.h"

#include "applib/ui/crumbs_layer.h"

struct ActionMenu {
  Window window;
};

typedef struct AnimationContext {
  Window *window;
  const ActionMenuLevel *next_level;
} AnimationContext;

typedef struct {
  const ActionMenuLevel *cur_level;
  int num_dots;
  GEdgeInsets menu_insets;
} ActionMenuViewModel;

typedef struct {
  ActionMenu action_menu;
  ActionMenuConfig config;
  ActionMenuLayer action_menu_layer;
  CrumbsLayer crumbs_layer;
  ActionMenuViewModel view_model;
  Animation *level_change_anim;
  const ActionMenuItem *performed_item;
  Window *result_window;
  bool frozen;
} ActionMenuData;

// ActionMenuItem is a union of two types:
// * In the leaf case we have:
//    perform_action is a valid pointer and thus is_leaf is non 0 (== true)
//    action_data is a valid pointer, next_level is not used
// * In the level case we have:
//    is_leaf is 0 (== false), perform_action is not a valid pointer
//    next_level points to a valid ActionMenuLevel, action_data is not used
struct ActionMenuItem {
  const char *label;
  union {
    ActionMenuPerformActionCb perform_action;
    uintptr_t is_leaf;
  };
  union {
    void *action_data;
    ActionMenuLevel *next_level;
  };
};

struct ActionMenuLevel {
  ActionMenuLevel *parent_level;
  uint16_t max_items;
  uint16_t num_items;
  unsigned default_selected_item;
  // The separator (dotted line) will appear just above this index (an index of 0 will be ignored)
  // [PG] It should be used to help differentiate item specific actions vs global actions.
  // Double check with design before using this for another purpose.
  unsigned separator_index;
  ActionMenuLevelDisplayMode display_mode;
  ActionMenuItem items[];
};
