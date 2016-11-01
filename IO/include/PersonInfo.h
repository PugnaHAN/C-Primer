#ifndef __PERSONINFO_H__
#define __PERSONINFO_H__

#include <string>
#include <vector>
#include <iostream>

class PersonInfo
{
  public:
	PersonInfo() = default;
	PersonInfo(std::string n, std::vector<std::string> phs) : name(n), phones(phs) {};
	
	std::string getName() const { return name; }
	std::vector<std::string> getPhones() const
	{
		// std::cout << phones.size() << std::endl;
		return phones;
	}
	void setName(std::string name) { this->name = name; }
	void setPhones(std::vector<std::string> phones)
	{ this->phones = phones; }
	void appendPhone(std::string& phone) {phones.push_back(phone);}
  private:
	std::string name;
	std::vector<std::string> phones;
};

#endif /* __PERSONINFO_H__ */
