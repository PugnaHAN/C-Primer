#include "Adapter.h"

#include <iostream>

using namespace std;

ExecuteInterface **initialize()
{
	ExecuteInterface **array = new ExecuteInterface *[3];

	/* Old functions */
	array[0] = new ExecuteAdapter<Fea>(new Fea(), &Fea::doThis);
	array[1] = new ExecuteAdapter<Feye>(new Feye, &Feye::doThat);
	array[2] = new ExecuteAdapter<Pheau>(new Pheau, &Pheau::doTheOther);

	return array;
}
