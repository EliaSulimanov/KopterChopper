#pragma once

#include "CPoint.h"

class CPolygon
{
public:
#pragma region CONSTRUCTORs & DESTRUCTOR0)
	CPolygon();
	CPolygon(int num_of_points);
	CPolygon(const CPolygon& polygon);
	~CPolygon();
#pragma endregion

#pragma region Setting polygon properties	
	void SetNumberOfPoints(int num_of_points);
	void SetPolygonColor(Color color_component, double color_value);
	void SetPolygonColor(double red_component, double green_component, double blue_component);
	void DuplicatePolygon(CPolygon polygon);
#pragma endregion

#pragma region Setting one point properties
	void SetOnePoint(int point_index, CPoint point);
	void SetOnePointCoordinates(int point_index, double x_coordinate, double y_coordinate, double z_coordinate);
	void SetOnePointColor(int point_index, Color color_component, double color_value);
	void SetOnePointColor(int point_index, double red_component, double green_component, double blue_component);
#pragma endregion

#pragma region Move polygon functions
	void MovePolygon(Axis axis, double move_value);
	void MovePolygon(double x_move, double y_move,double z_move);
	void MovePolygon(CPoint point_move);
	void MovePolygonCenter(Axis axis, double coordinate_value);
	void MovePolygonCenter(double x_coordinate, double y_coordinate, double z_coordinate);
	void MovePolygonCenter(CPoint point_coordinate);
#pragma endregion

#pragma region Scale polygon functions
	void ScalePolygon(Axis axis, double scale_ratio);
	void ScalePolygon(double x_ratio, double y_ratio, double z_ratio);
	void ScaleSelfPolygon(Axis axis, double scale_ratio);
	void ScaleSelfPolygon(double x_ratio, double y_ratio, double z_ratio);
#pragma endregion

#pragma region Rotate polygon functions
	void RotatePolygon(Axis axis, double rotate_value);
	void MovePolygonByVector(double angle, CPoint vector);
	void RotateSelfPolygon(Axis axis, double rotate_value);
#pragma endregion

#pragma region Draw polygon function
	void DrawPolygon();
#pragma endregion

#pragma region Get functions
	CPoint GetPoint(int point_index);
	CPoint GetPolygonCenter();
	int GetNumberOfPoints();
#pragma endregion

private:
#pragma region Private variables
	int _num_of_points;
	CPoint* _points_array;
#pragma endregion
};