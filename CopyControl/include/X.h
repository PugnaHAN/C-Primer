/*
 * This class is used to learn of constructor/deconstructor/copy control
 */

#ifndef __X_H__
#define __X_H__

#include "common.h"

class X
{
  public:
	X():name("No name") {std::cout << "X() - " << name << std::endl;}
	X(const std::string& n):name(n) {std::cout << "X(const string) - " << name << std::endl;}
	X(const X&) {std::cout << "X(const X&) - " << name << std::endl;}
	~X() {std::cout << "~X() - " << name << std::endl;}

  private:
	std::string name;
};

#endif /* __X_H__ */
