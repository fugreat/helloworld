Example "Hello, World!" C++ application and library that uses autotools to meet
requirements of a well behaved application and library with small effort.

This compiles an application called hello that prints "Hello, World!"
to stdout and also creates a library that provides an API to print
"World" to stdout.

Run './configure --help' to see options to tune installation, set build target,
customize feature set, customize optional external packages used, and modify
compiler/linkers and their command line flags.

Subset of targets available in this sample application:

    $ ./autogen.sh
    $ ./configure --enable-gcov --enable-valgrind --silent
    $ make
    $ make check
    $ make gtest-xml
    $ make gcovr
    $ make gcovr-xml
    $ make cppcheck
    $ make cppcheck-xml
    $ make flint
    $ make flint-xml
    $ make sonar-preare
    $ make sonar-incremental
    $ make install
    $ make doxygen-doc

The results of those targets will run unit tests and create a gtest compatible
XML report, create a valgrind memory leak report in XML format,
create gcov code coverage in XML format, generate static analysis reports
(cppcheck and flexelint), create a SonarQube Incremental Issue Report and
install hello application and world library+header file under /usr/local.

Metrics produced include the following formats that can be imported into
various CI and QA tools such as Jenkins and SonarQube:

 * test/valgrind-\*.xml
 * test/gtest.xml
 * coverage.xml
 * cppcheck.xml
 * flint.xml
 * .sonar/issues-report/issues-report.html

PDF, HTML, and MAN pages will exist under doxygen-doc.

