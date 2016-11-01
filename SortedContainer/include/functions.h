#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <vector>
#include <list>
#include <deque>
#include <iostream>

// 9.2.1
bool find(std::vector<int>::iterator, std::std::vector<int>::iterator, int);
std::vector<int>::iterator find_value(std::vector<int>::iterator,
									  std::vector<int>::iterator,
									  int);

// 9.2.5
void init_value(std::vector<std::string>&, std::list<char *>&);

// 9.2.7
bool is_equal(const std::vector<int>&, const std::vector<int>&);
bool is_equal(const std::vector<int>&, const std::list<int>&);

// 9.3.1
void print_input(std::ostream& os);

#endif /* __FUNCTIONS_H__ */

