#pragma once
#ifndef __TIME_H__
#define __TIME_H__

#include "TimeImp.h"

class Time
{
public:
	Time() = default;
	Time(int hr, int min) {	impl = new TimeImp(hr, min); }

	virtual void tell() { impl->tell(); }

protected:
	TimeImp* impl;
};

class CivilianTime : public Time
{
public:
	CivilianTime(int hr, int min, bool pm) { impl = new CivilianTimeImp(hr, min, pm); }
};

class ZuluTime : public Time
{
public:
	ZuluTime(int hr, int min, int zn) {	impl = new ZuluTimeImp(hr, min, zn); }
};

#endif /* __TIME_H__ */