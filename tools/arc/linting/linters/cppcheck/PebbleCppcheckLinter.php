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
 * Uses Cppcheck to do basic checks in a C++ file.
 */
final class PebbleCppcheckLinter extends ArcanistExternalLinter {

  public function getInfoName() {
    return 'Cppcheck-pebble';
  }

  public function getInfoURI() {
    return 'http://cppcheck.sourceforge.net';
  }

  public function getInfoDescription() {
    return pht('Use `cppcheck` to perform static analysis on C/C++ code.');
  }

  public function getLinterName() {
    return 'cppcheck-pebble';
  }

  public function getLinterConfigurationName() {
    return 'cppcheck-pebble';
  }

  public function getDefaultBinary() {
    return 'cppcheck';
  }

  public function getVersion() {
    list($stdout) = execx('%C --version', $this->getExecutableCommand());

    $matches = array();
    $regex = '/^Cppcheck (?P<version>\d+\.\d+)$/';
    if (preg_match($regex, $stdout, $matches)) {
      return $matches['version'];
    } else {
      return false;
    }
  }

  public function getInstallInstructions() {
    return pht('Install Cppcheck using `apt-get install cppcheck` for Ubuntu'.
               ' or `brew install cppcheck` for Mac OS X');
  }

  protected function getMandatoryFlags() {
    return array(
      '--quiet',
      '--inline-suppr',
      '--xml',
      '--xml-version=2',
    );
  }

  protected function getDefaultFlags() {
    return array('-j2',
                 '--enable=performance,style,portability,information',
                 '--library=tools/arc/linting/tintin.cfg,std',
                 '--rule-file=tools/arc/linting/tintin.rule',
                 '--enable=all',
                 '--suppress=passedByValue',
                 '--suppress=selfAssignment',
                 '--suppress=toomanyconfigs',
                 '--suppress=uninitStructMember',
                 '--suppress=unnecessaryForwardDeclaration',
                 '--suppress=unusedFunction',
                 '--suppress=variableScope',
                 '--suppress=unusedStructMember',
                 '--suppress=varFuncNullUB',
                 '--suppress=ConfigurationNotChecked');
  }

  protected function getDefaultMessageSeverity($code) {
    return ArcanistLintSeverity::SEVERITY_WARNING;
  }

  protected function parseLinterOutput($path, $err, $stdout, $stderr) {
    $dom = new DOMDocument();
    $ok = @$dom->loadXML($stderr);

    if (!$ok) {
      return false;
    }

    $errors = $dom->getElementsByTagName('error');
    $messages = array();
    foreach ($errors as $error) {
      foreach ($error->getElementsByTagName('location') as $location) {
        $message = new ArcanistLintMessage();
        $message->setPath($location->getAttribute('file'));
        $message->setLine($location->getAttribute('line'));
        $message->setCode($error->getAttribute('id'));
        $message->setName($error->getAttribute('id'));
        $message->setDescription($error->getAttribute('msg'));

        $message->setSeverity($this->getLintMessageSeverity($error->getAttribute('id')));

        $messages[] = $message;
      }
    }

    return $messages;
  }

  protected function getLintCodeFromLinterConfigurationKey($code) {
    if (!preg_match('@^[a-z_]+$@', $code)) {
      throw new Exception(
        pht(
          'Unrecognized severity code "%s". Expected a valid cppcheck '.
          'severity code like "%s" or "%s".',
          $code,
          'unreadVariable',
          'memleak'));
    }
    return $code;
  }
}
