#include "TextQuery.h"

using namespace std;

TextQuery::TextQuery(ifstream &file):contents(new vector<string>)
{
	string text;
	while (getline(file, text))
	{
		contents->push_back(text);
		int n = contents->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word)
		{
			auto &lines = word_map[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}	
}

QueryResult TextQuery::query(const std::string& sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	auto loc = word_map.find(sought);
	if (loc == word_map.end())
		return QueryResult(sought, nodata, contents);
	else
		return QueryResult(sought, loc->second, contents);
}