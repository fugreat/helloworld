AM_CPPFLAGS = -I$(top_srcdir)/src -DGTEST_HAS_PTHREAD=0

EXTRA_DIST = gtest-driver

XMLOPT = $(if $(findstring yes, $(CHECKXML)),--enable-xml)
check-xml-local:
	$(MAKE) check CHECKXML=yes

# List of executables to run as part of 'make check' target.
TESTS = helloworld_unittest$(EXEEXT)
# List of targets to build as part of 'make check' target.  These are not
# installed.
check_PROGRAMS = $(TESTS)
LOG_COMPILER = $(srcdir)/gtest-driver $(VALGRINDOPT) $(XMLOPT)  --

helloworld_unittest_SOURCES = helloworld_unittest.cc hello_test.cc \
			      world_test.cc gtest/gtest-all.cc gtest/gtest.h
# Note build directory and srcdir do not have to be same place.  This is how
# to support a single copy of source code used to cross compile to multiple
# hosts.
helloworld_unittest_LDADD = $(top_builddir)/src/helloworld/hello.$(OBJEXT) \
		   $(top_builddir)/src/helloworld/world/world.$(OBJEXT)
helloworld_unittest_LDFLAGS = -no-install

MOSTLYCLEANFILES = *.gcda *.gcno
MOSTLYCLEANFILES += gtest/*.gcda gtest/*.gcno
DISTCLEANFILES = *-gtest.xml *-valgrind.xml
