#pragma once
#ifndef __REG_FUNCTIONS_H__
#define __REG_FUNCTIONS_H__

#include "common.h"

bool spell_checker(const std::string&, const std::string&);
void check_phone(std::istream&);
bool valid(const std::smatch&);

#endif /* __REG_FUNCTIONS_H__ */