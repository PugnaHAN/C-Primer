#include "NotQuery.h"

using namespace std;

Query operator~(const Query& operand) {
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
	auto result = query.eval(text);
	auto all_lines = make_shared<set<line_no>>();
	auto beg = result.lines_begin(), end = result.lines_end();

	for (auto line = 0; line != result.get_file()->size(); ++line) {
		if (beg == end || *beg == line)
			all_lines->insert(line);
		else if (beg != end)
			++beg;
	}
	return QueryResult(rep(), all_lines, result.get_file());
}
