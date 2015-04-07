Overview
--------

This provides very basic information on working with this autotools based
C++ package.

Anything beyond the basics will require developers to read the various
manuals and tutorials available on the internet.

Recommended links:

 * Autoconf Manual
   * https://www.gnu.org/savannah-checkouts/gnu/autoconf/manual/autoconf-2.69/html_node/index.html
 * Automake Manual
   * http://www.gnu.org/software/automake/manual/html_node/index.html
 * Autotools Mythbuster - https://autotools.io/index.html

Parts of Autotools
------------------

Autotools is a collection of three main external tools:

 * autoconf - This is used to generate the 'configure' script from
   'configure.ac' and macros in 'm4' directory.
 * automake - This is used to generate 'Makefile.in' template file from
   'Makefile.am' files.
 * libtool - This is used to create shared and static libraries for a target
   in a platform independent way.

Normally, these commands are not ran directly by developers. Instead, the
included script 'autogen.sh' is ran after a fresh clone from git. Rules
exist in auto-generated Makefile that will also rerun a subset of those
tools when it sees modifications made to 'configure.ac' or 'Makefile.am' file.

The software can not be compiled until the user first runs the generated
configure script.  This script detects run time differences unique to
host. As a side effect, it will use 'Makefile.in' files as a template
to generate 'Makefile' with any host specific information.

Project Layout
--------------

The following directory structure exists with the following autotools related
files.  Each will be described in their own subsection.

    helloworld/
      m4/
      Makefile.am
      Makefile.am.*
      configure.ac
      src/
        Makefile.am
      test/
        Makefile.am

m4/ directory
-------------

When a piece of configure.ac logic is particularly complex or if a
pattern keeps repeating itself then people usually write m4 macros
to simplify configure.ac.  Those macros should be stored in
files under the 'm4/' directory.

If you have a configure.ac problem to solve, before writing your own macro
you should see if someone has written and contributed a macro first.

A list of popular macros is maintained by the autoconf team as part of their
autoconf-archive site.
http://www.gnu.org/software/autoconf-archive/The-Macros.html

configure.ac
------------

Any time a major release of the software package occurs, configure.ac
should be edited and modify the AC_INIT() second parameters with release #.

    AC_INIT([helloworld],[1.0],[],[],[http://rtx-swtl-git.fnc.net.local/projects/iprepo/repos/helloworld/browse])

The above line causes the following #defines to exist in your application:

 * PACKAGE_NAME - "helloworld"
 * PACKAGE_VERSION - "1.0"
 * PACKAGE_STRING - "helloworld 1.0"
 * PACKAGE_BUGREPORT - "http://rtx-swtl-git.fnc.net.local/projects/iprepo/repos/helloworld/browse"

TODO Items

 * TODO: Detecting external header files that require no library linking.
 * TODO: Detecting external header files and matching libraries.
 * TODO: Detect external executables (IDL compiler for example).
 * TODO: Making external item optional feature from command line.

src/Makefile.am
---------------

All application and library source files should go under 'src/' directory.
If a lot of files exist then its recommended to use subdirectories and
follow  Google C++ Coding Guideline conventions for \*.cc and \*.h
filenames.  When filenames in subdirectories are added to 'src/Makefile.am',
it should include full path relative to src directory.  For example,
'src/foo/foo.cc' would be added in 'src/Makefile.am' as 'foo/foo.cc'.

Items that will need updating or added when adding new files to template:

 * bin_PROGRAMS - list of executables to create and install under --bindir;
   which defaults to /usr/local/bin.
 * sbin_PROGRAMS - list of daemon executables to create an dinstall under
   --sbindir; which defaults to /usr/local/sbin.
 * lib_LTLIBRARIES - list of libtool based libraries to created and install
  under --libdir; which defaults to /usr/local/lib or /usr/local/lib64
  depending on target architecture.
 * nobase_include_HEADERS - list of header files to install under --includedir;
   which defalts to /usr/local/include. nobase  causes subdirectory
   hierarchy to be carried  over during install.
 * AM_CPPFLAGS/AM_CXXFLAGS/AM_LDFLAGS - compiler flags that should be used
   for all PROGRAMS and LTLIBRARIES defined in this Makefile.
 * AM_LIBADD - extra object files to add to all LTLIBRARIES.
 * AM_LDADD - extra object files to add to all PROGRAMS.

See "Other Derived Objects" in Automake Manual for less typical cases of
scripts, data files, or generated source.
http://www.gnu.org/software/automake/manual/html_node/Other-Objects.html

If a program was added to bin_PROGRAMS then lines need to be added that
describes both source code and libraries to compile and link into the program.

    hello_SOURCES = hell.cc hello.h main.cc
    hello_LDADD = libworld.la

In addtion to \_SOURCES and \_LDADD, \_CPPFLAGS, \_CXXFLAGS, and \_LDFLAGS
can be specified. Any AM\_{LDADD|CPPFLAGS|CXXFLAGS|LDFLAGS} will be lost in
that case and should be manually added back.

   hello_LDADD = $(AM_LDADD) libworld.la

If a library was added to either lib_LTLIBRARIES list or to an programs
\_LDADD list then lines need to be added that describes source code to
compile and add to library.

    libworld_la_SOURCES = world/world.cc 

In addtion to \_SOURCES, \_LIBADD, \_CPPFLAGS, \_CXXFLAGS, and \_LDFLAGS
can be specified. Any AM\_{LIBADD|CPPFLAGS|CXXFLAGS|LDFLAGS} will be lost in
that case and should be manually added back.

    libworld_la_CXXFLAGS = $(AM_CXXFLAGS) -DWORLD_FLAG

test/Makefile.am
----------------

All code should be unit tested.  One or more executable should be
generated to drive unit tests with the 'make check' target.

 * check_PROGRAMS - list of programs compiled as part of 'make check'
   target but not installed.
 * TESTS - list of programs or scripts to run as part of 'make check'.
   If program must be compiled first then it should appear in both
   TESTS and check_PROGRAMS.

For each program listed in check_PROGRAMS lists, lines must be added
to describe source code and libraries to compile and link into program.
Make use of '$(top_builddir)/src' prefix to link in object files compiled
under src directory.

    helloworld_unittest_SOURCE = hellworld_unittest.cc hello_test.cc \\
                                gtest/gtest-all.cc gtest/gtest.h
    hellworld_unittest_LDADD = $(top_builddir)/src/hello.$(OBJEXT)
    hellworld_unitest_LDFLAGS = -no-install
