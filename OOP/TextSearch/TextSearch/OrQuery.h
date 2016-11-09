#pragma once
#ifndef __ORQUERY_H__
#define __ORQUERY_H__

#include "BinaryQuery.h"

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query& l, const Query& r);
private:
	OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") {}
	QueryResult eval(const TextQuery&) const override;
};

#endif /* __ORQUERY_H__ */
