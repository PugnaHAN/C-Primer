#pragma once
#ifndef __ANDQUERY_H__
#define __ANDQUERY_H__

#include "BinaryQuery.h"

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query& l, const Query& r);
private:
	AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") {}
	QueryResult eval(const TextQuery&) const override;
};

#endif /* __ANDQUERY_H__ */