Example "Hello, World!" C++ application and library that uses autotools to meet
requirements of a well behaved application and library with small effort.

This compiles an application called hello that prints "Hello, World!"
to stdout and also creates a library that provides an API to print
"World" to stdout.

* note that for a freshly cloned repository, must execute ./autogen.sh first

Run './configure --help' to see options to tune installation, set build target,
customize feature set, customize optional external packages used, and modify
compiler/linkers and their command line flags.

Subset of targets available in this sample application:

    $ ./autogen.sh
    $ mkdir build
    $ cd build
    $ ../configure --prefix=`pwd`/debug --enable-gcov --enable-valgrind --silent
    $ make
    $ make doxygen-doc

The above installs and/or generates missing autotools files, runs configure
to install in a local debug directory as well as enable code coverage and
valgrind support during unit testing, compiles the library and application,
and generates API documentation in HTML, PDF, and man pages format.

By default, autotools generates applications/libraries with "-O2 -g" so
that they can be debugged.  If you prefer optimization turned off during
debugging, you can manually set default flags with configure:

    $ ../configure CXXFLAGS="-O0 -g" --prefix=`pwd`/debug --enable-gcov --enable-valgrind --silent

It is safe to always have debug enabled because you can chose to install with
or without debug symbols by choice of install target. Also, release applications
and libraries should not have gcov enabled and so the '--enable-gcov' should
be removed for most usecases of 'make install-strip'.

    $ make install
    $ make install-strip

The following unit test related targets exist.  They run unit tests using
automake's test framework and display code coverage reports on the terminal.
Unit tests create log files that can be reviewed for failure details.

    $ make check
    $ make gcovr

The following static analysis targets exist that are useful when ran from
a terminal or inside Vim/Eclipse/Emacs.  Since all reports are gnu gcc
compatible, most editors will populate their quickfix/problems windows
with the issues found.

    $ make cppcheck
    $ make cpplint

In vim use ':make analyze' to run all possible static analysis targets and
populate its quickfix list with the results. Eclipse's Problem window
can also be populated by changing the build target to 'analyze' and running
a build.

    $ make analyze

The following targets exist that are useful when used with automation
tools such as Jenkins and SonarQube. They generate gtest results in
its own XML format, Valgrind results in its own XML format,
Cobertura compatible XML from gcov data, cppcheck's data to its own XML
format, converts cpplint.py's output to checkstyle compatible XML, and dumps
flexelint to its own XML format.

    $ make check-xml
    $ make gcovr-xml
    $ make cppcheck-xml
    $ make cpplint-xml

The following 'sonar-prepare' is a convenience target that runs all previous
XML targets.

    $ make sonar-prepare

'sonar-incremental' will run sonar-prepare and also generate
an incremental issues HTML report that covers only modified files.
'sonar-preview' will run sonar-prepare and also generate a full issue HTML
report which can be filtered for only new items.

    $ make sonar-prepare
    $ make sonar-incremental
    $ make sonar-preview

The above targets will produce the following files:

 * src/hello
 * src/libworld.la
 * test/helloworld_unittest.log
 * test/helloworld_unittest-gtest.xml
 * test/helloworld_unittest-valgrind.xml
 * coverage.xml
 * cppcheck.xml
 * cpplint.txt
 * cpplint.xml
 * .sonar/issues-report/issues-report.html
 * doxygen-doc/*.pdf
 * doxygen-doc/html
 * doxygen-doc/man/man3

