#include "Client.h"

#include <iostream>

using namespace std;

void Client::process()
{
	Builder* worker = new Worker();
	Designer* designer = new Designer();

	designer->order(*worker);
	Room room = worker->getRoom();

	cout << "Room's window: " << room.getWindow().getName() << "\n"
		<< "\t" << "floor: " << room.getFloor().getName() << endl;

	delete worker;
	worker = nullptr;
	delete designer;
	designer = nullptr;
}