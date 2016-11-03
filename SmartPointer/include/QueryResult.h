#ifndef __QUERYRESULT_H__
#define __QUERYRESULT_H__

#include "common.h"

class QueryResult
{
	friend std::ostream& print(std::ostream&, const QueryResult&);
  public:
	QueryResult(std::string s,
				std::shared_ptr<std::set<line_no>,
				std::shared_ptr<std::vector<std::string>> f):
			sought(s), lines(p), file(f)
	{}
  private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

std::ostream &print(ostream &os, const QueryResult &qr);
#endif /* __QUERYRESULT_H__ */
