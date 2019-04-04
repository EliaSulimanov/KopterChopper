#pragma once

#include "CPoint.h"
#include "CPolygon.h"

class CModel
{
public:
#pragma region CONSTRUCTORs & DESTRUCTOR
	CModel();
	CModel(int num_of_polygons);
	CModel(const CModel& model);
	~CModel();
#pragma endregion
	
#pragma region Setting model properties
	void SetNumberOfPolygons(int num_of_polygons);
	void DuplicateModel(CModel model);
	void SetModelColor(Color color_component, double color_value);
	void SetModelColor(double red_component, double green_component, double blue_component);
#pragma endregion

#pragma region Setting one polygon properties
	void SetOnePolygon(int polygon_index, CPolygon polygon);
	void SetOnePolygonColor(int polygon_index, Color color_component, double color_value);
	void SetOnePolygonColor(int polygon_index, double red_component, double green_component, double blue_component);
#pragma endregion

#pragma region Move model functions
	void MoveModel(Axis axis, double move_value);
	void MoveModel(double x_move, double y_move,double z_move);
	void MoveModel(CPoint point_move);
	void MoveModelCenter(Axis axis, double coordinate_value);
	void MoveModelCenter(double x_coordinate, double y_coordinate,double z_coordinate);
	void MoveModelCenter(CPoint point_coordinate);
#pragma endregion

#pragma region Scale model functions
	void ScaleModel(Axis axis, double scale_ratio);
	void ScaleModel(double x_ratio, double y_ratio, double z_ratio);
	void ScaleSelfModel(Axis axis, double scale_ratio);
	void ScaleSelfModel(double x_ratio, double y_ratio, double z_ratio);
#pragma endregion

#pragma region Rotate model functions
	void RotateModel(Axis axis, double rotate_value);
	void RotateSelfModel(Axis axis, double rotate_value);
	void MoveModelByVector(double angle, CPoint vector);
#pragma endregion

#pragma region Draw model function
	void DrawModel();
#pragma endregion
	
#pragma region Get functions
	CPolygon GetPolygon(int polygon_index);
	CPoint GetModelCenter();
	int GetNumberOfPolygons();
#pragma endregion

protected:
#pragma region Private variables
	int _num_of_polygons;
	CPolygon* _polygons_array;
#pragma endregion
};