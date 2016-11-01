#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "common.h"

// 11.1
int word_cout(const std::string& word, std::istream& is, std::ostream& os);
void store_single_word(std::vector<std::string>& vec, std::istream& is);
std::vector< std::pair<std::string, int> > store_pairs(std::istream&);

#endif /* __FUNCTIONS_H__ */
