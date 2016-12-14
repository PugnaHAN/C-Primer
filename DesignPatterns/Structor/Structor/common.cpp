#include "common.h"

using namespace std;

void Pattern(const char* p)
{
	string pattern(p);
	auto sz = (LableLength - pattern.size()) >> 1;
	cout << string(sz, '-') << pattern
		<< string(sz + (pattern.size() % 2 ? 1 : 0), '-')
		<< endl;
}