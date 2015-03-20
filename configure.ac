dnl Please see Autoconf manual for details on modifying this file:
dnl
dnl http://www.gnu.org/savannah-checkouts/gnu/autoconf/manual/autoconf-2.69/html_node/index.html
dnl
dnl which is also viewable from GNU info tool:
dnl
dnl $ info autoconf
dnl
dnl Macros starting with AM_ prefix are described in Automake manual:
dnl
dnl http://www.gnu.org/software/automake/manual/html_node/index.html
dnl
dnl which is also viewable from GNU info tool:
dnl
dnl $ info automake

dnl Initialize autoconf.
dnl
dnl Package name and revision are used by 'make dist' and 'make install'
dnl targets as well as made available to application.
dnl
dnl See Section 4.1, 'Intializing configure', for more details
AC_INIT([helloworld],[1.0],[],[],[http://rtx-swtl-git.fnc.net.local/projects/iprepo/repos/helloworld/browse])

dnl Look for useful macros to enhance configure's behavior at
dnl http://www.gnu.org/software/autoconf-archive and place them
dnl the m4 directory.
AC_CONFIG_MACRO_DIR([m4])

dnl Initialize automake support and customize its behavior:
dnl
dnl 1.11 - Requires automake 1.11 or newer because of parallel-tests feature
dnl -Wall - Increase automake warning level
dnl -Werror - Turn automake warnings into errors.
dnl -Wno-portability - Allows us to use gmake extension and not be limitted
dnl to only features of POSIX make.
dnl foreign - turn off check for GNU file conventions (Changelog, NEWS, etc)
dnl parallel-tests - default to parallel test runner
dnl
dnl See Section automake's Section 17.2, ' List of Automake options',
dnl for more details.
AM_INIT_AUTOMAKE([1.11 -Wall -Werror -Wno-portability foreign parallel-tests subdir-objects])
dnl Display little during compiles.  Use 'make V=1' to be verbose.
AM_SILENT_RULES([yes])
dnl Default ismaintainer-mode enabled *but* without --disable-maintainer-mode
dnl arg. Calling AM_MAINTAINER_MODE enables by default and adds arg to disable.
AM_MAINTAINER_MODE([enable])

dnl General flow a configure script should take:
dnl
dnl * Check for installed programs
dnl  * Add --enable-*/--with-* options related to installed programs
dnl  * Set variables as needed to store information.
dnl  * Call AM_CONDITIONAL() and AC_SUBST() to pass info to application
dnl * Check for headers and supporting libraries
dnl  * Add --enable-*/--with-* options related to headres/libraries.
dnl  * Set variables as needed to store information.
dnl  * Call AM_CONDITIONAL() and AC_SUBST() to pass info to application
dnl * Check for typedefs, structures, and compiler characteristics.
dnl  * Add --enable-*/--with-* options related to checks.
dnl  * Set variables as needed to store information.
dnl  * Call AM_CONDITIONAL() and AC_SUBST() to pass info to application
dnl * Check for library functions.
dnl  * Add --enable-*/--with-* options related to checks.
dnl  * Set variables as needed to store information.
dnl  * Call AM_CONDITIONAL() and AC_SUBST() to pass info to application
dnl * Call AC_CONFIG_FILES() and AC_OUTPUT

dnl This is a C++ application and library. Autoconf default is for a C
dnl application/library.
AC_PROG_CXX
AC_LANG([C++])
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_MAKE_SET

dnl Add variable to increase compiler warnings for use by Makefile's. This
dnl is not added to global *FLAGS so it can be adjusted per application/library.
dnl If added globally, it tends to be immediately disabled for project at
dnl first compile failure during schedule pressure.
if test "$GXX" = yes; then
    WARNING_CFLAGS="-Wall -Werror"
    WARNING_CXXFLAGS="-Wall -Werror"
fi
AC_SUBST(WARNING_CFLAGS)
AC_SUBST(WARNING_CXXFLAGS)

dnl Since building a library, enable optional LIBTOOL support which deals
dnl with all the crazy OS level differences in library.  This also enables
dnl cross compiling support as a side effect.  If not building a library,
dnl this can be removed but needs to be replaced with AC_CANICAL_HOST to
dnl support cross compiling (LT_INIT calls this already).
LT_INIT

dnl Enabling valgrind will cause all host based unit tests to be ran with
dnl valgrind to detect memory leaks.  --error-exitcode will cause unit test to
dnl fail when leaks are detected. This option is only used by 'make check'
dnl target.
AC_ARG_ENABLE(valgrind,
	      AS_HELP_STRING([--enable-valgrind],
			     [Enable use of valgrind when running tests.]))

AS_IF([test "x$enable_valgrind" = "xyes"],
      [
       AC_CHECK_PROG(have_valgrind, valgrind, [yes], [no])
       AS_IF([test "x$have_valgrind" = "xno"],
	     AC_MSG_ERROR([Valgrind enabled but executable not found.]))
       ],
       [have_valgrind=no])

AS_IF([test "x$have_valgrind" = "xyes"],
      [VALGRINDOPT="--enable-valgrind"])
AC_SUBST(VALGRINDOPT)

dnl Enable gcov code coverage compiler options. This is useful for testing both
dnl host based compiles and cross compiles.  Since code coverage tests need
dnl to disable compiler optimization, this should not be used in shipping
dnl product.
AC_ARG_ENABLE(gcov,
	      AS_HELP_STRING([--enable-gcov],
			     [Enable gcov code coverage support.]))

AS_IF([test "x$enable_gcov" = "xyes"],
      [
       AS_IF([test "$GCC" != "yes"],
	     AC_MSG_ERROR([gcov enabled but compiler is not gcc.]))
       dnl Optimizations will defeat code coverage so remove those.
       changequote({,})
       CFLAGS=`echo "$CFLAGS" | sed -e 's/-O[0-9]*//g'`
       CXXFLAGS=`echo "$CXXFLAGS" | sed -e 's/-O[0-9]*//g'`
       changequote([,])
       CFLAGS="$CFLAGS -O0 -fprofile-arcs -ftest-coverage"
       CXXFLAGS="$CXXFLAGS -O0 -fprofile-arcs -ftest-coverage"
       LDFLAGS="$LDFLAGS -lgcov"
       ])

DX_MAN_FEATURE(ON)
DX_INIT_DOXYGEN([$PACKAGE_NAME], [doxygen.cfg])

dnl Inform autoconf of files that need substitution based on previous
dnl checks.
AC_CONFIG_FILES([Makefile src/Makefile test/Makefile])

dnl Generated output files with substitutions.
AC_OUTPUT

echo "Configure was successful.  Run 'make' to compile."
