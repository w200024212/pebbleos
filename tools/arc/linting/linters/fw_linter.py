#!/usr/bin/env python
# Copyright 2024 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


import re

# FW linters for tintin in python!
#
# Adding a new linter is simple. Simply,
# 1) Subclass FwLinter
# 2) Define found_lint_error(self, filename, line) and return True iff an error is found on the
#    line passed in
# 3) Define SEVERITY, NAME, MESSAGE as documented here:
#    https://secure.phabricator.com/book/phabricator/article/arcanist_lint_script_and_regex/


class FwLinter(object):
    def construct_arcanist_error_string(self, severity, name, message, filename, line_num):
        return '|'.join([severity, name, message, filename, line_num])

    def handle_lint_error(self, filename, line, line_num):
        """ Responsible for communicating the lint error to arcanist. Today, this just involves
        printing the message because 'arc lint' monitors stdout """
        print self.construct_arcanist_error_string(self.SEVERITY, self.NAME, self.MESSAGE,
                                                   filename, str(line_num))

    def found_lint_error(self, filename, line):
        """ Given a line, returns True if a lint error is found on the line and false otherwise """
        raise NotImplementedError


#
# FwLinter Subclasses
#

class TodoFixmeLinter(FwLinter):
    SEVERITY = "ADVICE"
    NAME = "TODO/FIXME"
    MESSAGE = "TODO/FIXME Found. Just letting you know"

    jira_ticket_id_regex = re.compile(r'PBL-\d+', re.IGNORECASE)

    def found_lint_error(self, filename, line):
        line_lowercase = line.lower()
        return 'todo' in line_lowercase or 'fixme' in line_lowercase

    def handle_lint_error(self, filename, line, line_num):
        message = self.MESSAGE
        # If we find a JIRA ticket ID in the line, add the full JIRA URL to the message
        jira_matches = self.jira_ticket_id_regex.findall(line)
        if jira_matches:
            jira_ticket_id = jira_matches[0]
            jira_base_url = 'https://pebbletechnology.atlassian.net/browse/'
            jira_url = jira_base_url + jira_ticket_id
            message = ' '.join([message, jira_url])
        print self.construct_arcanist_error_string(self.SEVERITY, self.NAME, message, filename,
                                                   str(line_num))


class UndefinedAttributeLinter(FwLinter):
    SEVERITY = "ERROR"
    NAME = "Undefined Attribute"
    MESSAGE = "yo, you need to include util/attributes.h if you want to PACK stuff"

    attribute_inc_regex = re.compile(r'(^#include\s+[<\"]util/attributes.h[>\"])')

    def __init__(self):
        self.include_found = False

    def found_lint_error(self, filename, line):
        if self.attribute_inc_regex.findall(line) or '#define PACKED' in line:
            self.include_found = True
            return False
        elif ' PACKED ' in line and not self.include_found:
            return True


class StaticFuncFormatLinter(FwLinter):
    SEVERITY = "WARNING"
    NAME = "Static Function Format Error"
    MESSAGE = "umm, you forgot to add 'prv_' or mark this function as 'static'"

    func_proto_regex = re.compile(r'^(\w+)\W?.*\W(\w+\([a-zA-Z])')

    def found_lint_error(self, filename, line):
        # Ignore header files
        if (filename.endswith(".h")):
            return False

        matches = self.func_proto_regex.findall(line)

        if matches and len(matches[0]) == 2:
            groups = matches[0]
            func_starts_with_prv = groups[1].startswith('prv_')
            func_is_static = any(x in groups[0] for x in ['static', 'T_STATIC'])

            return ((func_is_static and not func_starts_with_prv) or
                    (func_starts_with_prv and not func_is_static))
        return False


class ColorFallbackDeprecatedMacroLinter(FwLinter):
    SEVERITY = "WARNING"
    NAME = "COLOR_FALLBACK() Deprecated Macro"
    MESSAGE = "The macro `COLOR_FALLBACK()` has been deprecated for internal firmware use. " \
              "Use the equivalent `PBL_IF_COLOR_ELSE()` macro instead. Unfortunately, we can't " \
              "simply remove `COLOR_FALLBACK()` from the firmware because it's exported in the SDK."

    def found_lint_error(self, filename, line):
        return 'COLOR_FALLBACK' in line

#
# Code to run our FW linters
#


def lint(filename):
    linters = [linter() for linter in FwLinter.__subclasses__()]
    with open(filename) as f:
        for i, line in enumerate(f.readlines()):
            line_num = i + 1
            for linter in linters:
                if linter.found_lint_error(filename, line):
                    linter.handle_lint_error(filename, line, line_num)


if __name__ == '__main__':
    import sys
    filename = sys.argv[1]
    lint(filename)
