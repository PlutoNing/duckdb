#
# This is the DuckDB in-tree extension config as it will run on the CI
#
# to build duckdb with this configuration run:
#   EXTENSION_CONFIGS=.github/config/in_tree_extensions.cmake make
#

duckdb_extension_load(excel)
duckdb_extension_load(fts)
duckdb_extension_load(httpfs)
duckdb_extension_load(icu)
duckdb_extension_load(json DONT_LINK) # TODO WHY DOES JSON TEST FAIL IN EXTENSION TEST?
duckdb_extension_load(parquet)
duckdb_extension_load(tpcds)
duckdb_extension_load(tpch)
duckdb_extension_load(visualizer)