#include "OrQuery.h"

using namespace std;

QueryResult OrQuery::eval(const TextQuery &text) const
{
	auto right = rhs.eval(text), left = rhs.eval(text);
	auto ret_lines =
		make_shared<set<line_no>>(left.lines_begin(), left.lines_end());
	ret_lines->insert(right.lines_begin(), right.lines_end());
	return QueryResult(rep(), ret_lines, left.get_file());
}

Query operator|(const Query &lhs, const Query &rhs) {
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
