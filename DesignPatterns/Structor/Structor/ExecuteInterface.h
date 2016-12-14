#pragma once
#ifndef __EXECUTEINTERFACE_H__
#define __EXECUTEINTERFACE_H__

class ExecuteInterface {
public:
	// 1. Specify the new interface
	virtual ~ExecuteInterface() {};
	virtual void execute() = 0;
};

#endif /* __EXECUTEINTERFACE_H__ */