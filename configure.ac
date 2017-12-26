#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(split-gtk, 1.0, [http://split-gtk.sourceforge.net])
AC_CONFIG_SRCDIR([src/main.cpp])
AM_INIT_AUTOMAKE([dist-xz])
AC_CONFIG_HEADERS([config.h])

LT_INIT
PKG_PROG_PKG_CONFIG

AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AM_PROG_CC_C_O


# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST


dnl ================================================================
dnl Gettext stuff.
dnl ================================================================
GETTEXT_PACKAGE=split-gtk
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [Gettext package])
AM_GLIB_GNU_GETTEXT



# Checks for library functions.
DEP_MODULES="gtk+-3.0 glib-2.0"
PKG_CHECK_MODULES(SPLIT_GTK, $DEP_MODULES)

AC_ARG_ENABLE([deprecations],
	AS_HELP_STRING([--disable-deprecations],[Disable deprecated gtk functions (default: enabled)]),
	[enable_deprecations=$enableval],
	[enable_deprecations=yes])

if test "x$enable_deprecations" = "xno" ; then
	SPLIT_GTK_CFLAGS="$SPLIT_GTK_CFLAGS -DG_DISABLE_DEPRECATED  -DGDK_DISABLE_DEPRECATED -DGTK_DISABLE_DEPRECATED -DGDK_PIXBUF_DISABLE_DEPRECATED"
	SPLIT_GTK_CFLAGS="$SPLIT_GTK_CFLAGS -DG_DISABLE_SINGLE_INCLUDES -DATK_DISABLE_SINGLE_INCLUDES -DGDK_PIXBUF_DISABLE_SINGLE_INCLUDES -DGTK_DISABLE_SINGLE_INCLUDES"
fi

SPLIT_GTK_CFLAGS="-Wall $SPLIT_GTK_CFLAGS"


AC_CONFIG_FILES([
Makefile
src/Makefile
])
AC_OUTPUT

echo "

Type \"make\" to compile split-gtk.

"

