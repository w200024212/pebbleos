<?php
// Copyright 2024 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


/**
 * Runtime workflow configuration. In Arcanist, commands you type like
 * "arc diff" or "arc lint" are called "workflows". This class allows you to add
 * new workflows (and extend existing workflows) by subclassing it and then
 * pointing to your subclass in your project configuration.
 *
 * When specified as the **arcanist_configuration** class in your project's
 * ##.arcconfig##, your subclass will be instantiated (instead of this class)
 * and be able to handle all the method calls. In particular, you can:
 *
 *    - create, replace, or disable workflows by overriding buildWorkflow()
 *      and buildAllWorkflows();
 *    - add additional steps before or after workflows run by overriding
 *      willRunWorkflow() or didRunWorkflow() or didAbortWorkflow(); and
 *    - add new flags to existing workflows by overriding
 *      getCustomArgumentsForCommand().
 *
 * @concrete-extensible
 */
class PebbleArcanistConfiguration extends ArcanistConfiguration {
  const TREESTATUS_URL = "https://treestatus.marlinspike.hq.getpebble.com/api/ci/state/TT-MC/master";
  const FAIL_WHALE = "
  ▄██████████████▄▐█▄▄▄▄█▌
  ██████▌▄▌▄▐▐▌███▌▀▀██▀▀
  ████▄█▌▄▌▄▐▐▌▀███▄▄█▌
  ▄▄▄▄▄██████████████▀
";
  /*
   * Implement the willRunWorkflow hook in order to check whether or not
   * master is green before allowing a diff to be landed
   */
  public function willRunWorkflow($command, ArcanistWorkflow $workflow) {
    if ($workflow->getWorkflowName() == "land") {
      $build_status_str = file_get_contents(self::TREESTATUS_URL);
      $build_status = json_decode($build_status_str);

      $console = PhutilConsole::getConsole();
      if ($build_status->is_open) {
        $console->writeOut(
          "**<bg:green> %s </bg>** %s\n",
          pht('Master OK!'),
          pht('Merging is allowed'));
        return;
      } else {
        $console->writeOut(
          "%s\n**<bg:red> %s </bg>** %s\n",
          pht(self::FAIL_WHALE),
          pht('Master Borked :('),
          pht('Don\'t land unless your diff fixes it!'));

        if (!$console->confirm(pht('Land revision anyways?'))) {
          throw new ArcanistUserAbortException();
        }
      }
    }
  }
}
