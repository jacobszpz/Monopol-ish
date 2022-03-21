#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
# Copyright (C) 2022  Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>

AC_PREREQ([2.69])
AC_INIT([MONOPOLish], [0.0.1], [jsanchez-perez@uclan.ac.uk], [monopolish])
AC_LANG([C++])
AC_CONFIG_SRCDIR([src/CMonopolish.h])
# AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([pthread], [main],
	[AC_SUBST([LIBPTHREAD], ["-lpthread"])])

AC_CHECK_LIB([gtest_main], [main],
	[AC_SUBST([LIBGTEST], ["-lgtest -lgtest_main"])],
	[AC_MSG_WARN([libgtest entry point not found.])])

AC_SUBST(LIBPTHREAD)
AC_SUBST(LIBGTEST)

# Checks for header files.
AC_CHECK_HEADERS([gtest/gtest.h],,
	[AC_MSG_WARN([libgtest (Google C++ Unit Testing Framework) is not installed. Will not be able to run `make check`.])])

AC_CHECK_HEADERS([gmock/gmock.h],
	[AC_SUBST([LIBGMOCK], ["-lgmock"])],
	[AC_MSG_WARN([libgmock-dev is not installed. Will not be able to run `make check`.])])

AC_SUBST(LIBGMOCK)

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
