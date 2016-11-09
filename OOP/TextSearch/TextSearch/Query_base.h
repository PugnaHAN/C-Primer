#pragma once
#ifndef __QUERY_BASE_H__
#define __QUERY_BASE_H__

#include "common.h"
#include "TextQuery.h"
#include "QueryResult.h"

class Query;
class Query_base {
	friend class Query;
protected:
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const = 0;
};

#endif
