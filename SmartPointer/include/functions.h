#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "common.h"

// 10.1
std::vector<int>* dynamic_alloc(std::initializer_list<int> data);
std::vector<int>* get_more_data(std::istream&, std::vector<int>*);
void display(std::ostream&, std::vector<int>*);

std::shared_ptr<std::vector<int>> dynamic_alloc_sp(std::initializer_list<int> data);
std::shared_ptr<std::vector<int>> get_more_data_sp(std::istream&,
												   std::shared_ptr<std::vector<int>>);
void display(std::ostream&, std::shared_ptr<std::vector<int>>);

void display(std::ostream&, std::istream&);

#endif /* __FUNCTIONS_H__ */
