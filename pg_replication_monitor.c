/*-------------------------------------------------------------------------
 *
 * pg_replication_monitor.c
 *		Track statement execution times across a whole database cluster.
 *
 * Portions Copyright © 2018-2020, Percona LLC and/or its affiliates
 *
 * Portions Copyright (c) 1996-2020, PostgreSQL Global Development Group
 *
 * Portions Copyright (c) 1994, The Regents of the University of California
 *
 * IDENTIFICATION
 *	  contrib/pg_replication_monitor/pg_replication_monitor.c
 *
 *-------------------------------------------------------------------------
 */
#include "postgres.h"
#include "commands/explain.h"
#include "pg_replication_monitor.h"

PG_MODULE_MAGIC;

#define BUILD_VERSION                   "devel"

/*---- Initicalization Function Declarations ----*/
void _PG_init(void);
void _PG_fini(void);

// cppcheck-suppress unusedFunction
void
_PG_init(void)
{
	elog(DEBUG2, "pg_replication_monitor: %s()", __FUNCTION__);
	/*
	 * In order to create our shared memory area, we have to be loaded via
	 * shared_preload_libraries.  If not, fall out without hooking into any of
	 * the main system.  (We don't throw error here because it seems useful to
	 * allow the pg_stat_statements functions to be created even when the
	 * module isn't active.  The functions must protect themselves against
	 * being called then, however.)
	 */
	if (!process_shared_preload_libraries_in_progress)
		return;

	// EmitWarningsOnPlaceholders("pg_replication_monitor");
	// RequestAddinShmemSpace(hash_memsize() + HOOK_STATS_SIZE);
	RequestNamedLWLockTranche("pg_replication_monitor", 1);
}

/*
 * Module unload callback
 */
// cppcheck-suppress unusedFunction
void
_PG_fini(void)
{
}

