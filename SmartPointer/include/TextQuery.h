#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

#include "common.h"
#include "QueryResult.h"

class TextQuery
{
  public:
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;

  private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string,
			 std::shared_ptr<std::set<line_no>>> wm;
};

#endif /* __TEXTQUERY_H__ */
