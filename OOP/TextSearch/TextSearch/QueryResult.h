#pragma once
#ifndef __QUERYRESULT_H__
#define __QUERYRESULT_H__

#include "common.h"

class QueryResult
{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s,
		std::shared_ptr<std::set<line_no>> p,
		std::shared_ptr<std::vector<std::string>> f) :
		sought(s), lines(p), file(f) {}
	std::set<line_no>::iterator lines_begin() const { return lines->begin(); }
	std::set<line_no>::iterator lines_end() const { return lines->end(); }
	std::shared_ptr<std::vector<std::string>> get_file() { return file; }
	
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif
