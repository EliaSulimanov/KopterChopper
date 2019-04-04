#include "CModel.h"
#include "CSquare.h"
#include "CPolygon.h"
#include "CPoint.h"
#include "CCircle.h"
#include "CBall.h"

class CFuleStation
{
public:
	CFuleStation(void);
	void DrawFuleStation(void);
	CPoint GetMyCenter(void);
	void MoveMyCenter(double x_coordinate, double y_coordinate, double z_coordinate);
private:
	CModel _towerModel, _fuleTModel, _landSpace;
	double x,z;
};