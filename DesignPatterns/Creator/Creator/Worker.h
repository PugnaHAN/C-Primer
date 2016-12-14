#pragma once
#ifndef __WORKER_H__
#define __WORKER_H__

#include "Builder.h"

class Worker : public Builder
{
public:
	Worker() = default;
	~Worker() = default;

	void makeWindow() { room.setWindow(Window("window")); }
	void makeFloor() { room.setFloor(Floor("floor")); }

	Room getRoom() { return room; }
private:
	Room room;
};

#endif /* __WORKER_H__ */