#
# Makefile for utils
#
# src/backend/utils/Makefile
#

subdir = src/backend/utils
top_builddir = ../../..
include $(top_builddir)/src/Makefile.global

OBJS        = fmgrtab.o
SUBDIRS     = adt cache error fmgr hash init mb misc mmgr resowner sort time

# location of Catalog.pm
catalogdir  = $(top_srcdir)/src/backend/catalog

include $(top_srcdir)/src/backend/common.mk

all: errcodes.h fmgroids.h probes.h

$(SUBDIRS:%=%-recursive): fmgroids.h

# see explanation in ../parser/Makefile
fmgroids.h: fmgrtab.c ;

fmgrtab.c: Gen_fmgrtab.pl $(catalogdir)/Catalog.pm $(top_srcdir)/src/include/catalog/pg_proc.h
	rm -f pg_proc.h.c
	$(LN_S) $(top_srcdir)/src/include/catalog/pg_proc.h pg_proc.h.c
	$(CPP) -DBUILD_FMGRTAB -DCATALOG_VARLEN -DADB -o pg_proc.h pg_proc.h.c
	$(PERL) -I $(catalogdir) $< pg_proc.h
	rm -f pg_proc.h

errcodes.h: $(top_srcdir)/src/backend/utils/errcodes.txt generate-errcodes.pl
	$(PERL) $(srcdir)/generate-errcodes.pl $< > $@

ifneq ($(enable_dtrace), yes)
probes.h: Gen_dummy_probes.sed
endif

probes.h: probes.d
ifeq ($(enable_dtrace), yes)
	$(DTRACE) -C -h -s $< -o $@.tmp
	sed -e 's/POSTGRESQL_/TRACE_POSTGRESQL_/g' $@.tmp >$@
	rm $@.tmp
else
	sed -f $(srcdir)/Gen_dummy_probes.sed $< >$@
endif


# fmgroids.h, fmgrtab.c and errcodes.h are in the distribution tarball, so they
# are not cleaned here.
clean:
	rm -f probes.h

maintainer-clean: clean
	rm -f fmgroids.h fmgrtab.c errcodes.h
