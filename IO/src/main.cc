#include "functions.h"

using namespace std;

int main(int argc, char* argv[])
{
	// displayInstream(cin);

	vector<string> words;
	splitLine(words, "I am a hero");
	for(auto w : words)
	{
		cout << w << " ";
	}

	cout << endl;

	PersonInfo pi1, pi2;
	pi1.setName("Jack");
	pi1.setPhones({"13122334455", "02150987654"});
	
	pi2.setName("Robert");
	pi2.setPhones({"18512337654", "05985674532"});

	vector<PersonInfo> pis;
	pis.push_back(pi1);
	pis.push_back(pi2);

	print(pi1, cout);
}
