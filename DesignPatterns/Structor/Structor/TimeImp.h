#pragma once
#ifndef __TIMEIMP_H__
#define __TIMEIMP_H__

#include "common.h"

class TimeImp
{
public:
	TimeImp() = default;
	TimeImp(int hr, int min) : hour(hr), minute(min) {}

	virtual void tell()
	{ 
		std::cout << "time is " << std::setw(2) << std::setfill('0') 
			<< hour << ":" << minute << std::endl; 
	}

protected:
	int hour, minute;
};

class CivilianTimeImp : public TimeImp
{
public:
	CivilianTimeImp(int hr, int min, bool pm) : TimeImp(hr, min), 
		whichM(pm? "PM" : "AM") {}

	void tell() 
	{
		std::cout << "time is " << std::setw(2) << std::setfill('0') 
			<< hour << ":" << minute << " " << whichM << std::endl;
	}

private:
	std::string whichM;
};

class ZuluTimeImp : public TimeImp
{
public:
	ZuluTimeImp(int hr, int min, int zn) : TimeImp(hr, min)
	{
		if (zn == 5)
			zone = " Eastern Standard Time";
		else if (zn == 6)
			zone = " Central Standard Time";
	}
	void tell()
	{
		std::cout << "time is " << std::setw(2) << std::setfill(':')
			<< hour << ":" << minute << zone << std::endl;
	}
private:
	std::string zone;
};

#endif /* __TIMEIMP_H__ */