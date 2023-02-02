#include "duckdb/main/relation/read_json_relation.hpp"
#include "duckdb/parser/column_definition.hpp"
namespace duckdb {

ReadJSONRelation::ReadJSONRelation(const shared_ptr<ClientContext> &context, string json_file_p,
                                   named_parameter_map_t options, string alias_p)
    : TableFunctionRelation(context, "read_json", {Value(json_file_p)}, move(options)),
      json_file(std::move(json_file_p)), alias(std::move(alias_p)) {

	if (alias.empty()) {
		alias = StringUtil::Split(json_file, ".")[0];
	}
}

string ReadJSONRelation::GetAlias() {
	return alias;
}

} // namespace duckdb
