#pragma once
#ifndef __DESIGNER_H__
#define __DESIGNER_H__

#include "Builder.h"

class Designer
{
public:
	Designer() = default;
	~Designer() = default;

	void order(Builder& builder)
	{
		builder.makeFloor();
		builder.makeWindow();
	}
};

#endif /* __DESIGNER_H__ */