//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/parser/tableref/subqueryref.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/parser/statement/select_statement.hpp"
#include "duckdb/parser/tableref.hpp"

namespace duckdb {
//! Represents a subquery
class SubqueryRef : public TableRef {
public:
	SubqueryRef(unique_ptr<SelectStatement> subquery, string alias = string());

	//! The subquery
	unique_ptr<SelectStatement> subquery;
	//! Alises for the column names
	vector<string> column_name_alias;

public:
	bool Equals(const TableRef *other_) const override;

	unique_ptr<TableRef> Copy() override;

	//! Serializes a blob into a SubqueryRef
	void Serialize(Serializer &serializer) override;
	//! Deserializes a blob back into a SubqueryRef
	static unique_ptr<TableRef> Deserialize(Deserializer &source);
};
} // namespace duckdb
