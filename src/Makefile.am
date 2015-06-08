# Path to Exernal API header files
AM_CPPFLAGS = $(WARNING_CPPFLAGS)
AM_CXXFLAGS = $(WARNING_CXXFLAGS)

# List of targets to build and install in --bindir
bin_PROGRAMS = hello

# List of source files; including headers; used to produce hello executable.
# See automake for how to set compiler/linker flags per application.
hello_SOURCES = hello.cc hello.h main.cc
hello_LDADD = libworld.la

# List of LIBTOOL based targets to build and install in --libdir.
lib_LTLIBRARIES = libworld.la

# List of header files to install in --includedir. The nobase_ prefix
# causes subdirectory hiearchy to be carried over during install.
# world/world.h would be installed to ${includedir}/world/world.h
nobase_include_HEADERS = world/world.h

# List of source files used; including headers; used to produce libworld.la
# LIBTOOL based library.
# See automake for how to set compiler flags per library
libworld_la_SOURCES = world/world.cc

DISTCLEANFILES = *.gcov *.gcda *.gcno world/*.gcov world/*.gcda world/*.gcno
