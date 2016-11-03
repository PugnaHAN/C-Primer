#include "QueryResult.h"

using namespace std;

ostream& print(ostream& os, const QueryResult& qr)
{
	string time = qr.lines->size() > 1 ? "times" : "time";
	os << qr.sought << " occurs" << qr.lines->size() << " "
		<< time << endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") "
		   << *(qr.file->begin() + num) << endl;
	return os;
}