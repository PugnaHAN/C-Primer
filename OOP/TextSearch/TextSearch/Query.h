#pragma once
#ifndef __QUERY_H__
#define __QUERY_H__

#include "common.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include "Query_base.h"

class Query {
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
	friend std::ostream& operator<<(std::ostream&, const Query& query);

public:
	Query(const std::string&);

	QueryResult eval(const TextQuery&t) const {
		return q->eval(t);
	}
	std::string rep() const {
		return q->rep();
	}

private:
	Query(std::shared_ptr<Query_base> query) : q(query) {};
	std::shared_ptr<Query_base> q;
};

Query operator~(const Query&);
Query operator|(const Query&, const Query&);
Query operator&(const Query&, const Query&);
std::ostream& operator<<(std::ostream&, const Query& query);

#endif
