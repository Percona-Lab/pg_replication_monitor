/*-------------------------------------------------------------------------
 *
 * pg_replication_monitor.h
 *		Track statement execution times across a whole database cluster.
 *
 * Portions Copyright © 2018-2020, Percona LLC and/or its affiliates
 *
 * Portions Copyright (c) 1996-2020, PostgreSQL Global Development Group
 *
 * Portions Copyright (c) 1994, The Regents of the University of California
 *
 * IDENTIFICATION
 *	  contrib/pg_replication_monitor/pg_replication_monitor.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef __PG_replication_monitor_H__
#define __PG_replication_monitor_H__

#include "postgres.h"

#include <arpa/inet.h>
#include <math.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "access/hash.h"
#include "catalog/pg_authid.h"
#include "executor/instrument.h"
#include "common/ip.h"
#include "funcapi.h"
#include "access/twophase.h"
#include "mb/pg_wchar.h"
#include "miscadmin.h"
#include "optimizer/planner.h"
#include "postmaster/bgworker.h"
#include "parser/analyze.h"
#include "parser/parsetree.h"
#include "parser/scanner.h"
#include "parser/scansup.h"
#include "pgstat.h"
#include "storage/fd.h"
#include "storage/ipc.h"
#include "storage/spin.h"
#include "tcop/utility.h"
#include "utils/acl.h"
#include "utils/builtins.h"
#include "utils/memutils.h"
#include "utils/timestamp.h"
#include "utils/lsyscache.h"
#include "utils/guc.h"

#endif
