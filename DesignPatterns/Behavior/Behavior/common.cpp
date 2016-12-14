#include "common.h"

void Pattern(const std::string& pattern)
{
	auto sz = (60 - pattern.size()) >> 1;
	std::cout << std::string(sz, '-') << pattern
		<< std::string(sz + (pattern.size() % 2 ? 1 : 0), '-')
		<< std::endl;
}