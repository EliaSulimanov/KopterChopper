#include "CMap.h"
#include "CPoint.h"
#include "Common.h"
#include <stdlib.h>
#include <time.h>

class CMission
{
public:
	CMission(int _buildings_number);
	int GetMissionId();
	void SetNewMission(int _buildings_number);
	char* TextHendler(CPoint kopterCenter, CPoint buildingCenter);
private:
	int SelectRandomBuilding(int _buildings_number);
	int _mission_building_id;
};