Metrics
-------

This C++ template is capable of producing code quality metrics using
industry standard reporting formats.  They include:

 * Unit Tests ran and pass/fail status in Google Test XML format.
   * which in turn is slightly modified version of JUnit XML format.
 * Valgrind memory leaks using Valgrind XML format.
 * Code Coverage using Cobertura XML format.
 * cppcheck static analysis using cppcheck XML format.
 * Flexelint static analysis using PC-Lint XML format.
 * Google C++ Style Guidelines using checkstyle XML format.

Both Jenkins and SonarQube can consume these metrics and report using
a centralized dashboard.

In addition, these tools where chosen for their ability to integrate
into Eclipse/Vim/Emacs/most C++ IDE's.

If your component choses to deviate from this template then it is
your responability to also provide a replacement tool as well as an adapter
for your replacement that converts its metrics into one of the above
supported formats.

As an example, C or C++ code may wish to use Automake's built in
test runner instead of Google Test. If that is done then something
should be used to convert its status log files to GTest XML.

Automake Test Framework Manual:
https://www.gnu.org/software/automake/manual/html_node/Tests.html

Example python script that converts Automake status to GTest XML
(unsupported tool): /proj/common/tools/devtools/rhel6/bin/am2gtest.xml
