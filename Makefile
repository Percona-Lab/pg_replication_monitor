# contrib/pg_replication_monitor/Makefile

MODULE_big = pg_replication_monitor
OBJS = pg_replication_monitor.o $(WIN32RES)

EXTENSION = pg_replication_monitor
DATA = pg_replication_monitor--1.0.sql

PGFILEDESC = "pg_replication_monitor - replication statistics collector"

LDFLAGS_SL += $(filter -lm, $(LIBS)) 

REGRESS_OPTS = --temp-config $(top_srcdir)/contrib/pg_replication_monitor/pg_replication_monitor.conf --inputdir=regression
REGRESS = 

# Disabled because these tests require "shared_preload_libraries=pg_replication_monitor",
# which typical installcheck users do not have (e.g. buildfarm clients).
# NO_INSTALLCHECK = 1

ifdef USE_PGXS
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
else
subdir = contrib/pg_replication_monitor
top_builddir = ../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk
endif
