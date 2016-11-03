#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include "common.h"

class Employee
{
	friend std::ostream& display(std::ostream&, const Employee&);
  public:
	Employee();
	Employee(const Employee&);
	Employee(const std::string&);
	Employee& operator=(const Employee&);

  private:
	static unsigned int unique_id;
	unsigned int employ_id;
	std::string name;
};

std::ostream& display(std::ostream&, const Employee&);

#endif /* __EMPLOYEE_H__ */
