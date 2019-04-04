#include "CCube.h"
#include "CModel.h"
#include "CPolygon.h"
#include "CSquare.h"
#include "CCircle.h"

class CKopter:public CModel
{
	double v,vx,vy,vz,theta_y;
public:
	CKopter(void);
	void RotateKopterY(double angle);
	void MoveForward();
	void Accelerate(double v0);
	void RotatePropelor(double angle);
	void MoveFoword(CPoint kopterCenter, CPoint kopterNose);
};