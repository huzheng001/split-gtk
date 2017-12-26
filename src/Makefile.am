SUBDIRS= 

bin_PROGRAMS = split-gtk



AM_CPPFLAGS = $(SPLITGTK_CFLAGS) -I$(top_builddir) -I$(top_srcdir)	\
		-DSPLIT_GTK_LOCALEDIR=\""$(prefix)/$(DATADIRNAME)/locale"\"



split_gtk_LDFLAGS = 
split_gtk_LDADD = $(SPLITGTK_LIBS)
split_gtk_SOURCES = main.cpp


EXTRA_DIST = 
