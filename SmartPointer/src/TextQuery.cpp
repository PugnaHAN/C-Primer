#include "TextQuery.h"

using namespace std;

TextQuery::TextQuery(ifstream &is):file(new vector<string>)
{
	string text;
	text.mp
	while(getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while(line >> word)
		{
			auto &lines = wm[word];
			if(!line)
				line.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string &sought)
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}
