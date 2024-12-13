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

#include "console/prompt.h"
#include "process_management/app_install_manager.h"
#include "process_management/app_manager.h"
#include "services/normal/app_cache.h"
#include "services/normal/blob_db/app_db.h"
#include "services/normal/filesystem/pfs.h"

//! @file process_commands.c
//!
//! Serial commands for process management

extern AppInstallId app_db_check_next_unique_id(void);

void command_app_remove(const char *id_str) {
  int32_t id = atoi(id_str);
  if (id == 0) {
    prompt_send_response("invalid app number");
    return;
  }

  AppInstallEntry entry;
  if (!app_install_get_entry_for_install_id(id, &entry)) {
    prompt_send_response("failed to get entry");
    return;
  }

  // should delete from blob db and fire off an event to AppInstallManager that does the rest
  app_db_delete((uint8_t *)&entry.uuid, sizeof(Uuid));
  prompt_send_response("OK");
}

bool prv_print_app_info(AppInstallEntry *entry, void *data) {
  if (app_install_id_from_system(entry->install_id)) {
    return true;
  }

  char buffer[120];

  char uuid_buffer[UUID_STRING_BUFFER_LENGTH];
  uuid_to_string(&entry->uuid, uuid_buffer);

  prompt_send_response_fmt(buffer, sizeof(buffer), "%"PRIi32": %s %s", entry->install_id,
      entry->name, uuid_buffer);
  return true;
}

void command_app_list(void) {
  app_install_enumerate_entries(prv_print_app_info, NULL);
}

void command_app_launch(const char *id_str) {
  int32_t id = atoi(id_str);
  if (id == 0) {
    prompt_send_response("invalid app number");
    return;
  }

  AppInstallEntry entry;
  bool success = app_install_get_entry_for_install_id(id, &entry);

  if (success) {
    app_manager_put_launch_app_event(&(AppLaunchEventConfig) { .id = id });
    prompt_send_response("OK");
  } else {
    prompt_send_response("No app with id");
  }
}

void command_worker_launch(const char *id_str) {
  int32_t id = atoi(id_str);
  if (id == 0) {
    prompt_send_response("invalid app number");
    return;
  }

  AppInstallEntry entry;
  bool success = app_install_get_entry_for_install_id(id, &entry);

  if (success && app_install_entry_has_worker(&entry)) {
    app_manager_put_launch_app_event(&(AppLaunchEventConfig) { .id = id });
    prompt_send_response("OK");
  } else {
    prompt_send_response("No worker with id");
  }
}
