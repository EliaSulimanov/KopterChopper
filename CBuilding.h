#ifndef CBUILDING_H
#define CBUILDING_H
#include "CCube.h"
#include "CModel.h"
#include "CPolygon.h"

class CBuilding : public CModel{
public:
	CBuilding(void);
	void CBuilding::SetColorToOrig();
private:
	double frontColor,leftColor,rightColor,topColor;
	CPolygon front,left,right,top;
};
#endif