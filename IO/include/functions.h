#ifndef __FUCTIONS_H__
#define __FUCTIONS_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Sales_data.h"
#include "PersonInfo.h"

// 8.1
std::istream& displayInstream(std::istream& is);

// 8.2.1
enum ReadType
{
	readFile_type_start_e = 0,
	readFile_type_line_e,
	readFile_type_word_e,
	readFile_type_char_e,
	readFile_type_end_e,
};
std::vector<std::string> readFile(const std::string file, ReadType type);
void splitLine(std::vector<std::string>&, std::string);

// 8.2.2
void trade(std::string inputFile, std::string outputFile);

// 8.3.1
void read(std::vector<PersonInfo>&);
void print(PersonInfo& pi, std::ostream& os);
bool valid(const std::string& num);
std::string format(const std::string& number);

#endif /* __FUCTIONS_H__ */
