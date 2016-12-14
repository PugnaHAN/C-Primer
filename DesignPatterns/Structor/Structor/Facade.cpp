#include "Facade.h"

using namespace std;

bool FacilitiesFacade::checkOnStatus()
{
	++_count;
	switch (_state)
	{
	case Received:
		++_state;
		_engineer.submitNetworkRequest();
		cout << "submitted to Facilities - " << _count
			<< " phone calls so far" << endl;
		break;

	case SubmitToEngineer:
		if (_electrician.checkOnStatus())
		{
			++_state;
			_electrician.submitNetworkRequest();
			cout << "submitted to Electrician - " << _count <<
				" phone calls so far" << endl;
		}
		break;

	case SubmitToElectrician:
		if (_electrician.checkOnStatus())
		{
			_state++;
			_technician.submitNetworkRequest();
			cout << "submitted to MIS - " << _count <<
				" phone calls so far" << endl;
		}
		break;

	case SubmitToTechnician:
		return _technician.checkOnStatus();

	default:
		break;
	}
	return false;
}

void testFacade()
{
	FacilitiesFacade facilities;
	facilities.submitNetworkRequest();
	while (!facilities.checkOnStatus());
	cout << "job completed after only " << facilities.getNumberOfCalls() <<
		" phone calls" << endl;
}