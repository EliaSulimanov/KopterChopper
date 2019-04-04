#pragma once

//#include "CVectorRotation.h"

#pragma region ENUMs
enum Axis 
{
	X_AXIS = 1, 
	Y_AXIS = 2, 
	Z_AXIS = 3
};

enum Color 
{
	RED_COMPONENT = 1, 
	GREEN_COMPONENT = 2, 
	BLUE_COMPONENT = 3
};
#pragma endregion

class CPoint
{
public:

#pragma region CONSTRUCTORs
	CPoint();
	CPoint(double x_coordinate, double y_coordinate, double z_coordinate);
	CPoint(double x_coordinate, double y_coordinate, double z_coordinate, double red_component, double green_component, double blue_component);
#pragma endregion

#pragma region Move point functions
	void MovePoint(Axis axis, double move_value);
	void MovePoint(double x_move, double y_move, double z_move);
	void MovePoint(CPoint point_move);
#pragma endregion

#pragma region Set point location functions
	void SetPointCoordinate(Axis axis, double coordinate_value);
	void SetPointCoordinates(double x_coordinate, double y_coordinate, double z_coordinate);
#pragma endregion

#pragma region Scale point functions
	void ScalePoint(Axis axis, double scale_ratio);
	void ScalePoint(double x_ratio, double y_ratio, double z_ratio);
#pragma endregion

#pragma region Rotate point functions
	void RotatePoint(Axis axis, double rotate_value);
#pragma endregion

#pragma region Set point color functions
	void SetPointColor(Color color_component, double color_value);
	void SetPointColor(double red_component, double green_component, double blue_component);
#pragma endregion

#pragma region Get functions
	CPoint ClonePoint();
	double GetCoordinate(Axis axis);
	double GetColor(Color color_component);
#pragma endregion

#pragma region Draw function
	void DrawPoint();
#pragma endregion

	void MovePointByVector(double angle, CPoint vector);

private:
#pragma region Private variables
	double _x_coordinate;
	double _y_coordinate;
	double _z_coordinate;
	double _red_component;
	double _green_component;
	double _blue_component;
#pragma endregion

#pragma region Move point functions
	void MovePointX(double x_move);
	void MovePointY(double y_move);
	void MovePointZ(double z_move);
#pragma endregion

#pragma region Set point location functions
	void SetPointX(double x_coordinate);
	void SetPointY(double y_coordinate);
	void SetPointZ(double z_coordinate);
#pragma endregion

#pragma region Rotate point functions
	void RotatePointX(double x_rotate);
	void RotatePointY(double y_rotate);
	void RotatePointZ(double z_rotate);
#pragma endregion

#pragma region Set point color functions
	void SetPointRed(double red_component);
	void SetPointGreen(double green_component);
	void SetPointBlue(double blue_component);
#pragma endregion

#pragma region Get functions
	double GetX();
	double GetY();
	double GetZ();
	double GetRed();
	double GetGreen();
	double GetBlue();
#pragma endregion
};