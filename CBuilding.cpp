#include "CBuilding.h"
#include "CRoad.h"
#include <stdlib.h>
#include <cmath>
#include <time.h>

CBuilding::CBuilding()
{
	SetNumberOfPolygons(4);

	topColor = 0.0;
	rightColor = 0.0;
	leftColor = 0.0;
	frontColor = 0.0;
	
	srand( (unsigned)time( NULL ) );
	frontColor = fmod(rand() ,0.49 + 0.45);

	front.SetNumberOfPoints(4);
	front.SetOnePointCoordinates(0,-0.5,-1,0.5);
	front.SetOnePointCoordinates(1,0.5,-1,0.5);
	front.SetOnePointCoordinates(2,0.5,1,0.5);
	front.SetOnePointCoordinates(3,-0.5,1,0.5);
	front.SetPolygonColor(frontColor,frontColor,frontColor);
	SetOnePolygon(0, front);

	srand( (unsigned)time( NULL ) );
	leftColor = fmod(rand() , 0.49 + 0.4);

	left.SetNumberOfPoints(4);
	left.SetOnePointCoordinates(0,-0.5,-1,-0.5);
	left.SetOnePointCoordinates(1,-0.5,-1,0.5);
	left.SetOnePointCoordinates(2,-0.5,1,0.5);
	left.SetOnePointCoordinates(3,-0.5,1,-0.5);
	left.SetPolygonColor(leftColor,leftColor,leftColor);
	SetOnePolygon(1, left);

	srand( (unsigned)time( NULL ) );
	rightColor = fmod(rand() , 0.3 + 0.4);

	right.SetNumberOfPoints(4);
	right.SetOnePointCoordinates(3,0.5,-1,-0.5);
	right.SetOnePointCoordinates(2,0.5,-1,0.5);
	right.SetOnePointCoordinates(1,0.5,1,0.5);
	right.SetOnePointCoordinates(0,0.5,1,-0.5);
	right.SetPolygonColor(rightColor,rightColor,rightColor);
	SetOnePolygon(2, right);

	srand( (unsigned)time( NULL ) );
	topColor = fmod(rand() , 0.4 + 0.6);

	top.SetNumberOfPoints(4);
	top.SetOnePointCoordinates(3,0.5,1,-0.5);
	top.SetOnePointCoordinates(2,0.5,1,0.5);
	top.SetOnePointCoordinates(1,-0.5,1,0.5);
	top.SetOnePointCoordinates(0,-0.5,1,-0.5);
	top.SetPolygonColor(topColor,topColor,topColor);
	SetOnePolygon(3, top);
}

void CBuilding::SetColorToOrig()
{
	SetOnePolygonColor(0,frontColor,frontColor,frontColor);
	SetOnePolygonColor(1,leftColor,leftColor,leftColor);
	SetOnePolygonColor(2,rightColor,rightColor,rightColor);
	SetOnePolygonColor(3,topColor,topColor,topColor);
}