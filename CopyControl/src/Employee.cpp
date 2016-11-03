#include "Employee.h"

using namespace std;

unsigned int Employee::unique_id = 0;

Employee::Employee():employ_id(++unique_id), name("No name") {}
Employee::Employee(const string& n):employ_id(++unique_id), name(n) {}
Employee::Employee(const Employee& e):employ_id(e.employ_id), name(e.name) {}
Employee& Employee::operator=(const Employee& e)
{
	employ_id = e.employ_id;
	name = e.name;
	return *this;
}

ostream& display(ostream& os, const Employee& e)
{
	os << e.name << ": " << e.employ_id << endl;
	return os;
}
