#include "CPoint.h"
#include "CPolygon.h"
#include "CModel.h"
#include "CBuilding.h"
#include "CRoad.h"

class CMap
{
public:
	CMap(int x, int z);
	~CMap();

	void SetNumberOfModels(int num_of_models);

	void SetOneModelColor(int model_index, Color color_component, double color_value);
	void SetOneModelColor(int model_index, double red_component, double green_component, double blue_component);

	void MoveMap(Axis axis, double move_value);
	void MoveMap(double x_move, double y_move,double z_move);
	void MoveMap(CPoint point_move);
	void MoveMapCenter(Axis axis, double coordinate_value);
	void MoveMapCenter(double x_coordinate, double y_coordinate,double z_coordinate);
	void MoveMapCenter(CPoint point_coordinate);
	void SetHospitalBack();

	void RepaintBuildings();

	void DrawMap();

	CModel GetModel(int model_index);
	CPoint GetMapCenter();
	int GetNumberOfModels();

	int MakeMap();

protected:
	int _num_of_models;
	CBuilding* buildings_array;
	CRoad* roads_array;
	int _x,_z;
	int** map_array;
	//bool rnd;
};