#include "Proxy.h"

using namespace std;

string Person::nameList[] = { "Tom", "Dick", "Harry", "Bubba" };
int Person::next = 0;

bool PettyCash::withdraw(Person& p, int amount)
{
	auto name = p.getName();
	if (name == "Tom" || name == "Harry" || name == "Bubba")
		return realThing.withdraw(amount);
	else
		return false;
}

void testProxy()
{
	PettyCash pc;
	Person workers[4];
	for (int i = 0, amount = 100; i < 4; ++i, amount += 100)
		if (!pc.withdraw(workers[i], amount))
			cout << "No money for " << workers[i].getName() << "\n";
		else
			cout << " dollars for " << workers[i].getName() << "\n";
	cout << "Remaining balance is " << pc.getBalance() << endl;
}