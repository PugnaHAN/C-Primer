#pragma once
#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "Worker.h"
#include "Room.h"
#include "Designer.h"

class Client
{
public:
	Client() = default;
	~Client() = default;

	void process();
};

#endif /* __CLIENT_H__ */