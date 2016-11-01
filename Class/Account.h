#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <string>

class Account
{
  public:
	void calculate() { ammount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);

  private:
	std::string owner;
	double ammount;
	static double interestRate;
	static double initRate();
}


#endif /* __ACCOUNT_H__ */
