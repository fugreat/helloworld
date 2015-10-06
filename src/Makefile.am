# Path to Exernal API header files
AM_CPPFLAGS = $(WARNING_CPPFLAGS)
AM_CXXFLAGS = $(WARNING_CXXFLAGS)

# List of targets to build and install in --bindir
bin_PROGRAMS = hello

# List of source files; including headers; used to produce hello executable.
# See automake for how to set compiler/linker flags per application.
hello_SOURCES = helloworld/hello.cc helloworld/hello.h main.cc
hello_LDADD = libworld.la

# List of LIBTOOL based targets to build and install in --libdir.
lib_LTLIBRARIES = libworld.la

# List of header files to install in --includedir. The nobase_ prefix
# causes subdirectory hiearchy to be carried over during install.
# helloworld/world/world.h would be installed to
# ${includedir}/helloworld/world/world.h
nobase_include_HEADERS = helloworld/world/world.h

# List of source files used; including headers; used to produce libworld.la
# LIBTOOL based library.
# See automake for how to set compiler flags per library
libworld_la_SOURCES = helloworld/world/world.cc

MOSTLYCLEANFILES = *.gcda *.gcno
MOSTLYCLEANFILES += helloworld/*.gcda helloworld/*.gcno
MOSTLYCLEANFILES += helloworld/world/*.gcda helloworld/world/*.gcno
