#pragma once
#ifndef __BRIDGE_H__
#define __BRIDGE_H__

#include "Time.h"
#include "TimeImp.h"

void showTime()
{
	Time **times = new Time*[3];
	times[0] = new Time(14, 30);
	times[1] = new CivilianTime(2, 30, true);
	times[2] = new ZuluTime(14, 30, 6);

	for (int i = 0; i < 3; ++i)
		times[i]->tell();

	for (int i = 0; i < 3; ++i)
		delete times[i];

	delete times;
	times = nullptr;
}

#endif /* __BRIDGE_H__ */