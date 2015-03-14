# Point to public API that will be under test. Private can use paths
# in #include.
AM_CPPFLAGS = -I$(top_srcdir)/include

# List of executables to run as part of 'make check' target.
TESTS = hello_test$(EXEEXT) world_test$(EXEEXT)
# List of targets to build as part of 'make check' target.  These are not
# installed.
check_PROGRAMS = $(TESTS)
TESTS_ENVIRONMENT = $(VALGRIND)

hello_test_SOURCES = hello_test.cc
# Note build directory and srcdir do not have to be same place.  This is how
# to support a single copy of source code used to cross compile to multiple
# hosts.
hello_test_LDADD = $(top_builddir)/src/hello.$(OBJEXT) $(top_builddir)/src/world.$(OBJEXT)
hello_test_LDFLAGS = -no-install

world_test_SOURCES = world_test.cc
world_test_LDADD = $(top_builddir)/src/world.$(OBJEXT)
world_test_LDFLAGS = -no-install

DISTCLEANFILES = *.gcov *.gcda *.gcno valgrind-*.xml
