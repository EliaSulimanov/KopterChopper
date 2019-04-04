#include "CMap.h"
#include <stdlib.h>
#include <time.h>
CMap::CMap(int x, int z)
{
	_x=x;
	_z=z;
	
	int it=0;
	map_array = new int*[_x];
	for (int i = 0; i < _x; ++i)
		map_array[i] = new int[_z];
     _num_of_models = MakeMap();
	buildings_array = new CBuilding [_num_of_models+1];
	for (int i = 0; i < _x; ++i)
	{
		for (int j=0;j<_z;j++)
		{
			if (it<_num_of_models)
			{
				if (map_array[i][j])
					buildings_array[it++].MoveModelCenter(i*1.8,0,j*1.8);
			}
			else
			{
				break;
			}
		}
	}

}

void CMap::SetHospitalBack()
{
	buildings_array[0].SetModelColor(1,0,0);
}

CMap::~CMap()
{
	delete[] buildings_array;
	for (int i = 0; i < _x; ++i)
		delete [] map_array[i];
	delete [] map_array;
}

void CMap::SetNumberOfModels(int num_of_models)
{
	delete[] buildings_array;
	_num_of_models = num_of_models;	
	buildings_array = new CBuilding [_num_of_models];
}

CModel CMap::GetModel(int model_index)
{
	if(buildings_array[model_index].GetNumberOfPolygons()<0)
	{
		return 0;
	}
	return buildings_array[model_index];
}

void CMap::SetOneModelColor(int model_index, Color color_component, double color_value)
{
	buildings_array[model_index].SetModelColor(color_component, color_value);
}

void CMap::SetOneModelColor(int model_index, double red_component, double green_component, double blue_component)
{
	buildings_array[model_index].SetModelColor(red_component, green_component, blue_component);
}

void CMap::MoveMap(Axis axis, double move_value)
{
	for (int i = 0; i < _num_of_models; i++)
     buildings_array[i].MoveModel(axis,move_value);
}

void CMap::MoveMap(double x_move, double y_move,double z_move)
{
	for (int i = 0; i < _num_of_models; i++)
		buildings_array[i].MoveModel(x_move, y_move, z_move);
}

void CMap::MoveMap(CPoint point_move)
{
	for (int i = 0; i < _num_of_models; i++)
		buildings_array[i].MoveModel(point_move);
}

void CMap::MoveMapCenter(Axis axis, double coordinate_value)
{
	CPoint p = GetMapCenter();
	p.ScalePoint(-1, -1, -1);
	MoveMap(p);
	MoveMap(axis,  coordinate_value);
}

void CMap::MoveMapCenter(double x_coordinate, double y_coordinate, double z_coordinate)
{
	CPoint p = GetMapCenter();
	p.ScalePoint(-1, -1, -1);
	MoveMap(p);
	MoveMap(x_coordinate, y_coordinate, z_coordinate);
}

void CMap::MoveMapCenter(CPoint point_coordinate)
{
    CPoint p = GetMapCenter();
	p.ScalePoint(-1, -1, -1);
	MoveMap(p);
	MoveMap(point_coordinate);
}

void CMap::RepaintBuildings()
{
	for (int i = 0; i < _num_of_models; i++)
		buildings_array[i].SetColorToOrig();
}

void CMap::DrawMap()
{
	for (int i = 0; i < _num_of_models; i++)
		buildings_array[i].DrawModel();
}

CPoint CMap::GetMapCenter()
{
	CPoint sum(0, 0, 0);
	for (int i = 0; i < _num_of_models; i++)
		sum.MovePoint(buildings_array[i].GetModelCenter());
	double scale_ratio = 1.0/_num_of_models;
	sum.ScalePoint(scale_ratio, scale_ratio, scale_ratio);
	return sum;
}

int CMap::GetNumberOfModels()
{
	return _num_of_models;
}

int CMap::MakeMap()
{
	int counter=0;
	srand( (unsigned)time( NULL ) );
	for (int i = 0; i < _x; ++i){
		for (int j=0;j<_z;j++){
			int rnd=rand()%2;
			map_array[i][j]=rnd;
			if (rnd) counter++;
		}
	}
	return counter;
}