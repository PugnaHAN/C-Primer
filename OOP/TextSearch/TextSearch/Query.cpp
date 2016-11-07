#include "Query.h"
#include "WordQuery.h"

using namespace std;

Query::Query(const std::string &s): q(new WordQuery(s)){
}

ostream& operator<<(ostream& os, const Query& query) {
	return os << query.rep();
}