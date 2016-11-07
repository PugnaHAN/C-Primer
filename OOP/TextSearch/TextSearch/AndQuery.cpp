#include "AndQuery.h"

using namespace std;

QueryResult AndQuery::eval(const TextQuery& text) const
{
	auto right = rhs.eval(text), left = rhs.eval(text);
	auto ret_lines =
		make_shared<set<line_no>>(left.lines_begin(), left.lines_end());
	// ret_lines->erase(right.lines_begin(), right.lines_end());
	set_intersection(left.lines_begin(), left.lines_end(),
		right.lines_begin(), right.lines_end(),
		inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

Query operator&(const Query& l, const Query& r) {
	return std::shared_ptr<Query_base>(new AndQuery(l, r));
}