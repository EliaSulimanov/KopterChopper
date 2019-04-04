#include "CFuleStation.h"
#include <math.h>

CCircle _tower(30);
CCircle _tank(30);
CPolygon _poly, _landBig, _landSmall;
double _red;
bool _on;
CBall _towerTopBall(10, 10);
CModel _lands;
CModel * _modelsArray;
CFuleStation::CFuleStation(void)
{
	_modelsArray = new CModel[4];
	_on = true;
	_red = 0;
	_poly.SetNumberOfPoints(3);
	CPoint _point;
	/***********************************************************/
	_towerModel.SetNumberOfPolygons(601);
	for (int i=0; i<600; i++)
	{
		_point.SetPointCoordinates(-.5,0,0);
		_poly.SetOnePoint(0, _point);
		_point.SetPointCoordinates(.5,0,0);
		_poly.SetOnePoint(1, _point);
		_point.SetPointCoordinates(0,2,0);
		_poly.SetOnePoint(2, _point);
		_poly.RotateSelfPolygon(Y_AXIS,0.8*i);
		_towerModel.SetOnePolygon(i,_poly);
	}
	_tower.MovePolygonCenter(0,0,0);
	_tower.RotateSelfPolygon(X_AXIS, -90);
	_tower.ScaleSelfPolygon(0.5,0.5,0.5);
	_towerModel.SetOnePolygon(600,_tower);
	_towerTopBall.ScaleSelfModel(0.3, 0.3, 0.3);
	_towerModel.MoveModelCenter(0, 0, 1);
	_towerModel.SetModelColor(0.55,0.55,0.55);
	_towerTopBall.MoveModelCenter(_towerModel.GetModelCenter().GetCoordinate(X_AXIS),_poly.GetPoint(2).GetCoordinate(Y_AXIS)-0.5,_towerModel.GetModelCenter().GetCoordinate(Z_AXIS));
	/***********************************************************/
	_fuleTModel.SetNumberOfPolygons(602);
	_poly.SetNumberOfPoints(4);
	for (int i=0; i<600; i++)
	{
		_point.SetPointCoordinates(-.5,1,0);
		_poly.SetOnePoint(0, _point);
		_point.SetPointCoordinates(.5,1,0);
		_poly.SetOnePoint(1, _point);
		_point.SetPointCoordinates(.5,-1,0);
		_poly.SetOnePoint(2, _point);
		_point.SetPointCoordinates(-.5,-1,0);
		_poly.SetOnePoint(3, _point);
		_poly.RotateSelfPolygon(Y_AXIS,0.8*i);
		_poly.SetPolygonColor(0.5,0.5,0.5);
		_fuleTModel.SetOnePolygon(i,_poly);
	}
	_tank.MovePolygonCenter(0,-1,0);
	_tank.RotateSelfPolygon(X_AXIS, 90);
	_tank.ScaleSelfPolygon(0.5,0.5,0.5);
	_tank.SetPolygonColor(0.6,0.6,0.6);
	_fuleTModel.SetOnePolygon(600, _tank);
	_tank.SetPolygonColor(1,1,1);
	_tank.MovePolygonCenter(0,1,0);
	_fuleTModel.SetOnePolygon(601, _tank);
	_fuleTModel.RotateSelfModel(X_AXIS, -90);
	_fuleTModel.MoveModelCenter(-5, 0, 2);
	/***********************************************************/
	_landSmall.SetNumberOfPoints(4);
	_landSmall.SetOnePointCoordinates(0,1,1,0);
	_landSmall.SetOnePointCoordinates(1,1,-1,0);
	_landSmall.SetOnePointCoordinates(2,-1,-1,0);
	_landSmall.SetOnePointCoordinates(3,-1,1,0);
	_landSmall.RotateSelfPolygon(X_AXIS, 90);
	_landSmall.SetPolygonColor(1,0,0);
	_landSmall.ScaleSelfPolygon(1.7,1.7,1.7);
	_landSmall.MovePolygonCenter((_towerModel.GetModelCenter().GetCoordinate(X_AXIS)+_fuleTModel.GetModelCenter().GetCoordinate(X_AXIS))/2,-0.8,0);
	_landBig.SetNumberOfPoints(4);
	_landBig.SetOnePointCoordinates(0,1,1,0);
	_landBig.SetOnePointCoordinates(1,1,-1,0);
	_landBig.SetOnePointCoordinates(2,-1,-1,0);
	_landBig.SetOnePointCoordinates(3,-1,1,0);
	_landBig.RotateSelfPolygon(X_AXIS, 90);
	_landBig.SetPolygonColor(0,1,0);
	_landBig.ScaleSelfPolygon(1.8,1.8,1.8);
	_landBig.MovePolygonCenter((_towerModel.GetModelCenter().GetCoordinate(X_AXIS)+_fuleTModel.GetModelCenter().GetCoordinate(X_AXIS))/2,-0.8,0);
	_landBig.MovePolygon(Y_AXIS,-0.01);
	_lands.SetNumberOfPolygons(2);
	_lands.SetOnePolygon(0, _landBig);
	_lands.SetOnePolygon(1, _landSmall);
	/***********************************************************/
	_modelsArray[0]=_towerModel;
	_modelsArray[1]=_towerTopBall;
	_modelsArray[2]=_fuleTModel;
	_modelsArray[3]=_lands;
}

void CFuleStation::DrawFuleStation()
{
	for(int i = 0; i < 4; i++)
		_modelsArray[i].DrawModel();
	_towerTopBall.SetModelColor(_red,0,0);
	if(_on)
		_red += 0.005;
	else
		_red -= 0.005;
	if(_red >= 1)
		_on = false;
	if(_red <= 0)
		_on = true;
}

CPoint CFuleStation::GetMyCenter()
{
	CPoint sum(0, 0, 0);
	for (int i = 0; i < 4; i++)
		sum.MovePoint(_modelsArray[i].GetModelCenter());
	double scale_ratio = 1.0/4;
	sum.ScalePoint(scale_ratio, scale_ratio, scale_ratio);
	return sum;
}

void CFuleStation::MoveMyCenter(double x_coordinate, double y_coordinate, double z_coordinate)
{
	CPoint p = GetMyCenter();
	p.ScalePoint(-1, -1, -1);
	for (int i = 0; i < 4; i++)
	{
		_modelsArray[i].MoveModel(p);
		_modelsArray[i].MoveModel(x_coordinate, y_coordinate, z_coordinate);
	}
}