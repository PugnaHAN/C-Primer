#pragma once
#ifndef __NOTQUERY_H__
#define __NOTQUERY_H__

#include "common.h"
#include "Query_base.h"
#include "Query.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include "functions.h"

class NotQuery : public Query_base
{
	friend Query operator~(const Query&);
	NotQuery(const Query &q) : query(q) { }

	std::string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&) const override;
	Query query;
};

#endif /* __NOTQUERY_H__ */