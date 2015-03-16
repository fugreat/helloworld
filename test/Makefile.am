# Point to public API that will be under test. Private can use paths
# in #include.
AM_CPPFLAGS = -I$(top_srcdir)/include -DGTEST_HAS_PTHREAD=0

EXTRA_DIST = gtest-driver

# List of executables to run as part of 'make check' target.
TESTS = helloworld_unittest$(EXEEXT)
# List of targets to build as part of 'make check' target.  These are not
# installed.
check_PROGRAMS = $(TESTS)
TESTS_ENVIRONMENT = $(srcdir)/gtest-driver $(VALGRINDOPT) --

helloworld_unittest_SOURCES = helloworld_unittest.cc hello_test.cc \
			      world_test.cc gtest/gtest-all.cc gtest/gtest.h
# Note build directory and srcdir do not have to be same place.  This is how
# to support a single copy of source code used to cross compile to multiple
# hosts.
helloworld_unittest_LDADD = $(top_builddir)/src/hello.$(OBJEXT) \
		   $(top_builddir)/src/world.$(OBJEXT)
helloworld_unittest_LDFLAGS = -no-install

DISTCLEANFILES = *.gcov *.gcda *.gcno *-gtest.xml *-valgrind.xml \
		 gtest/*.gcov gtest/*.gcda gtest/*.gcno
