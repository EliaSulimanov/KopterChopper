#pragma once
#include "CPolygon.h"

class CCircle : public CPolygon
{
public:
	CCircle(void);
	CCircle(int num_of_points);
	void SetNumberOfPoints(int num_of_points);
};
