#pragma once
#ifndef __BUILDER_H__
#define __BUILDER_H__

#include "Room.h"

class Builder
{
public:
	Builder() = default;
	~Builder() = default;

	virtual void makeWindow() = 0;
	virtual void makeFloor() = 0;
	
	virtual Room getRoom() = 0;
};

#endif /* __BUILDER_H__ */