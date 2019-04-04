#include "CCircle.h"
#include <math.h>

const float PI = (float)3.1415926536;

CCircle::CCircle(void)
{
	SetNumberOfPoints(4);
}

CCircle::CCircle(int num_of_points)
{
	SetNumberOfPoints(num_of_points);
}

void CCircle::SetNumberOfPoints(int num_of_points)
{
	CPolygon::SetNumberOfPoints(num_of_points);

	double delta_angle = 2*PI/num_of_points;

	for (int i=0; i<num_of_points; i++)
	{
		double angle = i*delta_angle;
		double x = cos(angle);
		double y = sin(angle);
		SetOnePointCoordinates(i, x, y, 0);
	}

	SetPolygonColor(0, 0, 0);
}

