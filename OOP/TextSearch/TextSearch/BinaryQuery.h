#pragma once
#ifndef __BINARYQUERY_H__
#define __BINARYQUERY_H__

#include "Query_base.h"
#include "Query.h"
#include "functions.h"

class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) :
		lhs(l), rhs(r), opSym(s) { }
	std::string rep() const {
		return "(" + lhs.rep() + " "
			+ opSym + " " + rhs.rep() + ")";
	}

	Query lhs, rhs;
	std::string opSym;
};

#endif /* __BINARYQUERY_H__ */