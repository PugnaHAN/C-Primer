#pragma once
#ifndef __FACADE_H__
#define __FACADE_H__

#include "common.h"

class NetworkBase
{
public:
	virtual void submitNetworkRequest() { _state = 0; }
	virtual bool checkOnStatus() = 0;

protected:
	int _state = 0;
};

class MisDepartment: public NetworkBase
{
public:
	bool checkOnStatus() { return ++_state == Compete; }
private:
	enum State
	{
		Received, DenyAllKnowledge, ReferClientToFacilities,
		FacilitiesHasNotSentPaperwork, ElectrcianIsNotDone,
		ElectricianDidItWrong, DispatchTechnician, SignedOff, 
		DoesNotWork, FixElectricianWiring, Compete
	};
};

class ElectricianUnion: public NetworkBase
{
public:
	bool checkOnStatus() { return ++_state == Complete; }
private:
	enum States
	{
		Received, RejectTheForm, SizeTheJob, SmokeAndJokeBreak,
		WaitForAuthorization, DoTheWrongJob, BlameTheEngineer, WaitToPunchOut,
		DoHalfAJob, ComplainToEngineer, GetClarification, CompleteTheJob,
		TurnInThePaperwork, Complete
	};
};

class FacilitiesDepartment: public NetworkBase
{
public:
	bool checkOnStatus() { return ++_state == Complete; }
private:
	enum States
	{
		Received, AssignToEngineer, EngineerResearches, RequestIsNotPossible,
		EngineerLeavesCompany, AssignToNewEngineer, NewEngineerResearches,
		ReassignEngineer, EngineerReturns, EngineerResearchesAgain,
		EngineerFillsOutPaperWork, Complete
	};
};

class FacilitiesFacade: public NetworkBase
{
public:
	FacilitiesFacade(): _count(0) { }
	bool checkOnStatus();
	int getNumberOfCalls() { return _count; }
private:
	enum States { Received, SubmitToEngineer, SubmitToElectrician, SubmitToTechnician };
	int _count;
	FacilitiesDepartment _engineer;
	ElectricianUnion _electrician;
	MisDepartment _technician;
};

void testFacade();

#endif /* __FACADE_H__ */