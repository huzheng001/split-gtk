#!/bin/sh

(libtoolize --version) < /dev/null > /dev/null 2>&1 || {
	echo;
	echo "You must have libtool installed to compile split-gtk";
	echo;
	exit;
}

(automake --version) < /dev/null > /dev/null 2>&1 || {
	echo;
	echo "You must have automake installed to compile split-gtk";
	echo;
	exit;
}

(autoconf --version) < /dev/null > /dev/null 2>&1 || {
	echo;
	echo "You must have autoconf installed to compile split-gtk";
	echo;
	exit;
}

echo "Generating configuration files for split-gtk, please wait...."
echo;

echo "Running libtoolize, please ignore non-fatal messages...."
echo n | libtoolize --copy --force || exit;

echo "Running aclocal...."
aclocal || exit;
echo "Running autoheader...."
autoheader || exit;
echo "Running automake --add-missing --copy...."
automake --add-missing --copy;
echo "Running autoconf ...."
autoconf || exit;
echo "Running automake ...."
automake || exit;
./configure --prefix=/usr --sysconfdir=/etc --mandir=/usr/share/man --disable-deprecations $@
