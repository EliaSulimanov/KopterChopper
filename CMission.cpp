#include "CMission.h"

CMission::CMission(int _buildings_number)
{
	_mission_building_id = SelectRandomBuilding(_buildings_number);
}

int CMission::SelectRandomBuilding(int _buildings_number)
{
	srand((unsigned)time(NULL));
	if (_buildings_number==0) return 0;
	int a = rand() % _buildings_number;
	if(a == _buildings_number)
	{
		a--;
	}
	if(a == 0)
	{
		a++;
	}
	return a;
}

void CMission::SetNewMission(int _buildings_number)
{
	_mission_building_id = SelectRandomBuilding(_buildings_number);
}

int CMission::GetMissionId()
{
	return _mission_building_id;
}