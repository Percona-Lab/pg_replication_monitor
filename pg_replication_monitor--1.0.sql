/* contrib/pg_replication_monitor/pg_replication_monitor--1.1.sql */

-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION pg_replication_monitor" to load this file. \quit

-- Register functions.
CREATE FUNCTION pg_replication_monitor_reset()
RETURNS void
AS 'MODULE_PATHNAME'
LANGUAGE C PARALLEL SAFE;

CREATE FUNCTION pg_replication_monitor_version()
RETURNS text
AS 'MODULE_PATHNAME'
LANGUAGE C PARALLEL SAFE;

CREATE FUNCTION pg_replication_monitor_internal()
RETURNS SETOF record
AS 'MODULE_PATHNAME', 'pg_replication_monitor'
LANGUAGE C STRICT VOLATILE PARALLEL SAFE;

-- Register a view on the function for ease of use.
CREATE VIEW pg_replication_monitor AS SELECT
    1
FROM pg_replication_monitor_internal()
ORDER BY bucket_start_time;

GRANT SELECT ON pg_replication_monitor TO PUBLIC;
REVOKE ALL ON FUNCTION pg_replication_monitor_reset() FROM PUBLIC;
