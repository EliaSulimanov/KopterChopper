#include "CKopter.h"
#include <math.h>
const float PI = (float)3.1415926536;
CKopter::CKopter()
{
	SetNumberOfPolygons(31);
	CSquare MainBodyUp;
	MainBodyUp.SetNumberOfPoints(4);
	MainBodyUp.SetOnePointCoordinates(0,-0.5,1,2.5);
	MainBodyUp.SetOnePointCoordinates(1,-0.5,1,0);
	MainBodyUp.SetOnePointCoordinates(2,0.5,1,0);
	MainBodyUp.SetOnePointCoordinates(3,0.5,1,2.5);
	MainBodyUp.SetPolygonColor(0.6,0.6,0.6);
	MainBodyUp.RotateSelfPolygon(Z_AXIS,180);
	SetOnePolygon(0, MainBodyUp);

	CSquare MainBodyRight;
	MainBodyRight.SetNumberOfPoints(4);
	MainBodyRight.SetOnePoint(0,MainBodyUp.GetPoint(3));
	MainBodyRight.SetOnePoint(1,MainBodyUp.GetPoint(2));
	MainBodyRight.SetOnePointCoordinates(2,MainBodyUp.GetPoint(3).GetCoordinate(X_AXIS),0,MainBodyUp.GetPoint(1).GetCoordinate(Z_AXIS));
	MainBodyRight.SetOnePointCoordinates(3,MainBodyUp.GetPoint(3).GetCoordinate(X_AXIS),MainBodyRight.GetPoint(2).GetCoordinate(Y_AXIS),MainBodyUp.GetPoint(0).GetCoordinate(Z_AXIS));
	MainBodyRight.SetPolygonColor(0.7,0.7,0.7);
	SetOnePolygon(1, MainBodyRight);

	CSquare MainBodyLeft;
	MainBodyLeft.SetNumberOfPoints(4);
	MainBodyLeft.SetOnePoint(0,MainBodyUp.GetPoint(0));
	MainBodyLeft.SetOnePoint(1,MainBodyUp.GetPoint(1));
	MainBodyLeft.SetOnePointCoordinates(2,MainBodyUp.GetPoint(1).GetCoordinate(X_AXIS),MainBodyRight.GetPoint(2).GetCoordinate(Y_AXIS),MainBodyUp.GetPoint(1).GetCoordinate(Z_AXIS));
	MainBodyLeft.SetOnePointCoordinates(3,MainBodyUp.GetPoint(1).GetCoordinate(X_AXIS),MainBodyRight.GetPoint(2).GetCoordinate(Y_AXIS),MainBodyUp.GetPoint(0).GetCoordinate(Z_AXIS));
	MainBodyLeft.RotateSelfPolygon(Y_AXIS, 180);
	MainBodyLeft.SetPolygonColor(0.5,0.5,0.5);
	SetOnePolygon(2, MainBodyLeft);

	CSquare MainBodyFront;
	MainBodyFront.SetNumberOfPoints(4);
	MainBodyFront.SetOnePointCoordinates(0,-0.5,1,2.5);
	MainBodyFront.SetOnePointCoordinates(1,-0.5,0,2.5);
	MainBodyFront.SetOnePointCoordinates(2,0.5,0,2.5);
	MainBodyFront.SetOnePointCoordinates(3,0.5,1,2.5);
	MainBodyFront.SetPolygonColor(0,0,0);
	SetOnePolygon(3, MainBodyFront);

	CSquare MainLowRight;
	MainLowRight.SetNumberOfPoints(4);
	MainLowRight.SetOnePointCoordinates(0,-0.5,0,2.5);
	MainLowRight.SetOnePointCoordinates(1,-0.5,-0.3,2.5);
	MainLowRight.SetOnePointCoordinates(2,-0.5,-0.3,0);
	MainLowRight.SetOnePointCoordinates(3,-0.5,0,0);
	MainLowRight.RotateSelfPolygon(Y_AXIS,180);
	MainLowRight.SetPolygonColor(0.5,0.5,0.5);
	SetOnePolygon(4, MainLowRight);

	CSquare MainLowLeft;
	MainLowLeft.SetNumberOfPoints(4);
	MainLowLeft.SetOnePointCoordinates(0,0.5,0,2.5);
	MainLowLeft.SetOnePointCoordinates(1,0.5,-0.3,2.5);
	MainLowLeft.SetOnePointCoordinates(2,0.5,-0.3,0);
	MainLowLeft.SetOnePointCoordinates(3,0.5,0,0);
	MainLowLeft.SetPolygonColor(0.3,0.3,0.3);
	SetOnePolygon(5, MainLowLeft);

	CSquare FeetRootRight;
	FeetRootRight.SetNumberOfPoints(4);
	FeetRootRight.SetOnePointCoordinates(0,-0.4,MainBodyRight.GetPoint(2).GetCoordinate(Y_AXIS),4);
	FeetRootRight.SetOnePointCoordinates(1,FeetRootRight.GetPoint(0).GetCoordinate(X_AXIS),-0.3,FeetRootRight.GetPoint(0).GetCoordinate(Z_AXIS));
	FeetRootRight.SetOnePointCoordinates(2,MainBodyUp.GetPoint(2).GetCoordinate(X_AXIS),FeetRootRight.GetPoint(1).GetCoordinate(Y_AXIS),MainBodyUp.GetPoint(0).GetCoordinate(Z_AXIS));
	FeetRootRight.SetOnePointCoordinates(3,MainBodyUp.GetPoint(3).GetCoordinate(X_AXIS),MainBodyRight.GetPoint(2).GetCoordinate(Y_AXIS),MainBodyRight.GetPoint(0).GetCoordinate(Z_AXIS));
	FeetRootRight.RotateSelfPolygon(Y_AXIS,180);
	FeetRootRight.SetPolygonColor(0.4,0.4,0.4);
	SetOnePolygon(6, FeetRootRight);

	CSquare FeetRootLeft;
	FeetRootLeft.SetNumberOfPoints(4);
	FeetRootLeft.SetOnePointCoordinates(0,-FeetRootRight.GetPoint(3).GetCoordinate(X_AXIS),FeetRootRight.GetPoint(0).GetCoordinate(Y_AXIS),FeetRootRight.GetPoint(3).GetCoordinate(Z_AXIS));
	FeetRootLeft.SetOnePointCoordinates(1,FeetRootLeft.GetPoint(0).GetCoordinate(X_AXIS),FeetRootRight.GetPoint(1).GetCoordinate(Y_AXIS),FeetRootRight.GetPoint(2).GetCoordinate(Z_AXIS));
	FeetRootLeft.SetOnePointCoordinates(2,MainBodyUp.GetPoint(0).GetCoordinate(X_AXIS),FeetRootRight.GetPoint(1).GetCoordinate(Y_AXIS),MainBodyUp.GetPoint(0).GetCoordinate(Z_AXIS));
	FeetRootLeft.SetOnePointCoordinates(3,MainBodyUp.GetPoint(0).GetCoordinate(X_AXIS),MainBodyRight.GetPoint(2).GetCoordinate(Y_AXIS),MainBodyUp.GetPoint(0).GetCoordinate(Z_AXIS));
	FeetRootLeft.SetPolygonColor(0.2,0.2,0.2);
	SetOnePolygon(7, FeetRootLeft);

	CSquare FeetRootFront;
	FeetRootFront.SetNumberOfPoints(4);
	FeetRootFront.SetOnePointCoordinates(0,-FeetRootRight.GetPoint(3).GetCoordinate(X_AXIS),MainBodyRight.GetPoint(2).GetCoordinate(Y_AXIS),FeetRootRight.GetPoint(3).GetCoordinate(Z_AXIS));
	FeetRootFront.SetOnePoint(1,FeetRootRight.GetPoint(3));
	FeetRootFront.SetOnePointCoordinates(2,FeetRootRight.GetPoint(3).GetCoordinate(X_AXIS),FeetRootLeft.GetPoint(1).GetCoordinate(Y_AXIS),FeetRootRight.GetPoint(3).GetCoordinate(Z_AXIS));
	FeetRootFront.SetOnePointCoordinates(3,-FeetRootRight.GetPoint(3).GetCoordinate(X_AXIS),FeetRootRight.GetPoint(1).GetCoordinate(Y_AXIS),FeetRootRight.GetPoint(3).GetCoordinate(Z_AXIS));
	FeetRootFront.SetOnePointColor(1,0.3,0.3,0.3);
	FeetRootFront.SetOnePointColor(2,0.3,0.3,0.3);
	FeetRootFront.SetOnePointColor(0,0.2,0.2,0.2);
	FeetRootFront.SetOnePointColor(3,0.2,0.2,0.2);
	SetOnePolygon(8, FeetRootFront);

	CSquare WindowFront;
	WindowFront.SetNumberOfPoints(4);
	WindowFront.SetOnePointCoordinates(0,-0.4,0,2.5);
	WindowFront.SetOnePointCoordinates(1,-0.4,1,4);
	WindowFront.SetOnePointCoordinates(2,0.4,1,4);
	WindowFront.SetOnePointCoordinates(3,0.4,0,2.5);
	WindowFront.RotateSelfPolygon(Y_AXIS,180);
	WindowFront.SetPolygonColor(0,0,1);
	WindowFront.SetOnePointColor(0,0,0,0.7);
	SetOnePolygon(9, WindowFront);

	CSquare WindowLeft;
	WindowLeft.SetNumberOfPoints(3);
	WindowLeft.SetOnePointCoordinates(0,0.4,0,4);
	WindowLeft.SetOnePoint(1,MainBodyLeft.GetPoint(2));
	WindowLeft.SetOnePointCoordinates(2,0.4,1,2.5);
	WindowLeft.SetPolygonColor(0,0,0.7);
	SetOnePolygon(10, WindowLeft);

	CSquare WindowRight;
	WindowRight.SetNumberOfPoints(3);
	WindowRight.SetOnePointCoordinates(2,-0.4,0,4);
	WindowRight.SetOnePointCoordinates(1,MainBodyRight.GetPoint(3).GetCoordinate(X_AXIS),MainBodyRight.GetPoint(3).GetCoordinate(Y_AXIS),MainBodyRight.GetPoint(3).GetCoordinate(Z_AXIS));
	WindowRight.SetOnePointCoordinates(0,-0.4,1,2.5);
	WindowRight.SetPolygonColor(0.1,0.5,1);
	SetOnePolygon(11, WindowRight);

	CSquare TailUp;
	TailUp.SetNumberOfPoints(4);
	TailUp.SetOnePointCoordinates(0,-0.25,0.5,0);
	TailUp.SetOnePointCoordinates(1,-0.25,0.5,-3.75);
	TailUp.SetOnePointCoordinates(2,0.25,0.5,-3.75);
	TailUp.SetOnePointCoordinates(3,0.25,0.5,0);
	TailUp.RotateSelfPolygon(Z_AXIS,180);
	TailUp.SetPolygonColor(0.3,0.3,0.3);
	SetOnePolygon(12, TailUp);

	CSquare TailRight;
	TailRight.SetNumberOfPoints(4);
	TailRight.SetOnePointCoordinates(0,-0.25,0,0);
	TailRight.SetOnePointCoordinates(1,-0.25,0,-3.75);
	TailRight.SetOnePointCoordinates(2,-0.25,0.5,-3.75);
	TailRight.SetOnePointCoordinates(3,-0.25,0.5,0);
	TailRight.RotateSelfPolygon(Z_AXIS,180);
	TailRight.SetOnePointColor(0,0.3,0.3,0.3);
	TailRight.SetOnePointColor(1,0.3,0.3,0.3);
	TailRight.SetOnePointColor(2,0.4,0.4,0.4);
	TailRight.SetOnePointColor(3,0.4,0.4,0.4);
	SetOnePolygon(13, TailRight);

	CSquare TailLeft;
	TailLeft.SetNumberOfPoints(4);
	TailLeft.SetOnePointCoordinates(0,0.25,0,0);
	TailLeft.SetOnePointCoordinates(1,0.25,0,-3.75);
	TailLeft.SetOnePointCoordinates(2,0.25,0.5,-3.75);
	TailLeft.SetOnePointCoordinates(3,0.25,0.5,0);
	TailLeft.SetOnePointColor(3,0.3,0.3,0.3);
	TailLeft.SetOnePointColor(2,0.3,0.3,0.3);
	TailLeft.SetOnePointColor(1,0.2,0.2,0.2);
	TailLeft.SetOnePointColor(0,0.2,0.2,0.2);
	SetOnePolygon(14, TailLeft);

	CSquare TailBack;
	TailBack.SetNumberOfPoints(4);
	TailBack.SetOnePointCoordinates(0,-0.5,0.5,-3.75);
	TailBack.SetOnePointCoordinates(1,-0.5,0,-3.75);
	TailBack.SetOnePointCoordinates(2,0.5,0,-3.75);
	TailBack.SetOnePointCoordinates(3,0.5,0.5,-3.75);
	TailBack.ScaleSelfPolygon(0.5,1,1.5);
	TailBack.RotateSelfPolygon(Y_AXIS, 180);
	TailBack.SetOnePointColor(0,0.3,0.3,0.3);
	TailBack.SetOnePointColor(1,0.2,0.2,0.2);
	TailBack.SetOnePointColor(2,0.31,0.31,0.31);
	TailBack.SetOnePointColor(3,0.3,0.3,0.3);
	SetOnePolygon(15, TailBack);

	CSquare TailConnectionTop;
	TailConnectionTop.SetNumberOfPoints(3);
	TailConnectionTop.SetOnePointCoordinates(0,-0.5,1,0);
	TailConnectionTop.SetOnePointCoordinates(1,0.5,1,0);
	TailConnectionTop.SetOnePointCoordinates(2,0,0,-1);
	TailConnectionTop.SetOnePointColor(0,0.6,0.6,0.6);
	TailConnectionTop.SetOnePointColor(1,0.6,0.6,0.6);
	TailConnectionTop.SetOnePointColor(2,0.3,0.3,0.3);
	SetOnePolygon(16, TailConnectionTop);

	CSquare TailConnectionLeft;
	TailConnectionLeft.SetNumberOfPoints(3);
	TailConnectionLeft.SetOnePointCoordinates(0,0.5,1,0);
	TailConnectionLeft.SetOnePointCoordinates(1,0.5,-0.3,0);
	TailConnectionLeft.SetOnePointCoordinates(2,0,0,-1);
	TailConnectionLeft.SetOnePointColor(0,0.5,0.5,0.5);
	TailConnectionLeft.SetOnePointColor(1,0.2,0.2,0.2);
	TailConnectionLeft.SetOnePointColor(2,0.2,0.2,0.2);
	SetOnePolygon(17, TailConnectionLeft);

	CSquare TailConnectionRight;
	TailConnectionRight.SetNumberOfPoints(3);
	TailConnectionRight.SetOnePointCoordinates(2,-0.5,1,0);
	TailConnectionRight.SetOnePointCoordinates(1,-0.5,-0.3,0);
	TailConnectionRight.SetOnePointCoordinates(0,0,0,-1);
	TailConnectionRight.SetOnePointColor(1,0.4,0.4,0.4);
	TailConnectionRight.SetOnePointColor(0,0.5,0.5,0.5);
	TailConnectionRight.SetOnePointColor(2,0.7,0.7,0.7);
	SetOnePolygon(18, TailConnectionRight);

	CSquare PropelorPin1;
	PropelorPin1.SetNumberOfPoints(4);
	PropelorPin1.SetOnePointCoordinates(0,0,1.25,1.25);
	PropelorPin1.SetOnePointCoordinates(1,0.05,1,1.25);
	//Added one more point to make a vector
	PropelorPin1.SetOnePointCoordinates(2,0,1,1.25);
	PropelorPin1.SetOnePointCoordinates(3,-0.05,1,1.25);
	PropelorPin1.SetPolygonColor(1,1,1);
	SetOnePolygon(19, PropelorPin1);

	CSquare PropelorPin2;
	PropelorPin2.SetNumberOfPoints(3);
	PropelorPin2.SetOnePointCoordinates(2,0,1.25,1.25);
	PropelorPin2.SetOnePointCoordinates(1,0.05,1,1.25);
	PropelorPin2.SetOnePointCoordinates(0,-0.05,1,1.25);
	PropelorPin2.SetPolygonColor(1,1,1);
	SetOnePolygon(20, PropelorPin2);

	CSquare PropelorPin3;
	PropelorPin3.SetNumberOfPoints(3);
	PropelorPin3.SetOnePointCoordinates(0,0,1.25,1.25);
	PropelorPin3.SetOnePointCoordinates(1,0.05,1,1.25);
	PropelorPin3.SetOnePointCoordinates(2,-0.05,1,1.25);
	PropelorPin3.SetPolygonColor(1,1,1);
	PropelorPin3.RotateSelfPolygon(Y_AXIS,90);
	SetOnePolygon(21, PropelorPin3);

	CSquare PropelorPin4;
	PropelorPin4.SetNumberOfPoints(3);
	PropelorPin4.SetOnePointCoordinates(2,0,1.25,1.25);
	PropelorPin4.SetOnePointCoordinates(1,0.05,1,1.25);
	PropelorPin4.SetOnePointCoordinates(0,-0.05,1,1.25);
	PropelorPin4.SetPolygonColor(1,1,1);
	PropelorPin4.RotateSelfPolygon(Y_AXIS,90);
	SetOnePolygon(22, PropelorPin4);

	CCircle PropelorPinCircle;
	PropelorPinCircle.SetNumberOfPoints(10);
	PropelorPinCircle.MovePolygonCenter(0,1.01,1.25);
	PropelorPinCircle.ScaleSelfPolygon(0.1,0.1,0.1);
	PropelorPinCircle.RotateSelfPolygon(X_AXIS,-90);
	SetOnePolygon(23, PropelorPinCircle);

	CSquare PropelorTailPin1;
	PropelorTailPin1.SetNumberOfPoints(4);
	PropelorTailPin1.SetOnePointCoordinates(0,0.5,0.25,-3.5);
	PropelorTailPin1.SetOnePointCoordinates(1,0.25,0.3,-3.5);
	//vector point
	PropelorTailPin1.SetOnePointCoordinates(3,0.25,0.25,-3.5);
	PropelorTailPin1.SetOnePointCoordinates(2,0.25,0.2,-3.5);
	PropelorTailPin1.SetPolygonColor(1,1,1);
	SetOnePolygon(24, PropelorTailPin1);

	CSquare PropelorTailPin2;
	PropelorTailPin2.SetNumberOfPoints(3);
	PropelorTailPin2.SetOnePointCoordinates(2,0.5,0.25,-3.5);
	PropelorTailPin2.SetOnePointCoordinates(1,0.25,0.3,-3.5);
	PropelorTailPin2.SetOnePointCoordinates(0,0.25,0.2,-3.5);
	PropelorTailPin2.SetPolygonColor(1,1,1);
	SetOnePolygon(25, PropelorTailPin2);

	CSquare PropelorTailPin3;
	PropelorTailPin3.SetNumberOfPoints(3);
	PropelorTailPin3.SetOnePointCoordinates(2,0.5,0.25,-3.5);
	PropelorTailPin3.SetOnePointCoordinates(1,0.25,0.3,-3.5);
	PropelorTailPin3.SetOnePointCoordinates(0,0.25,0.2,-3.5);
	PropelorTailPin3.SetPolygonColor(1,1,1);
	PropelorTailPin3.RotateSelfPolygon(X_AXIS,90);
	SetOnePolygon(26, PropelorTailPin3);

	CCircle PropelorTailPinCircle;
	PropelorTailPinCircle.SetNumberOfPoints(10);
	PropelorTailPinCircle.MovePolygonCenter(0.26,0.25,-3.5);
	PropelorTailPinCircle.ScaleSelfPolygon(0.07,0.07,0.07);
	PropelorTailPinCircle.RotateSelfPolygon(Y_AXIS,90);
	SetOnePolygon(27, PropelorTailPinCircle);

	CSquare Propelor;
	Propelor.SetNumberOfPoints(4);
	Propelor.SetOnePointCoordinates(0,2,1.25,1);
	Propelor.SetOnePointCoordinates(1,-2,1.25,1);
	Propelor.SetOnePointCoordinates(2,-2,1.25,-1);
	Propelor.SetOnePointCoordinates(3,2,1.25,-1);
	Propelor.MovePolygonCenter(PropelorPin1.GetPoint(0));
	Propelor.ScaleSelfPolygon(0.01,1,2.6);
	Propelor.RotateSelfPolygon(X_AXIS,180);
	Propelor.SetPolygonColor(1,1,1);
	SetOnePolygon(28, Propelor);

	
	CSquare PropelorTail;
	PropelorTail.SetNumberOfPoints(4);
	PropelorTail.SetOnePointCoordinates(0,2,1.25,1);
	PropelorTail.SetOnePointCoordinates(1,-2,1.25,1);
	PropelorTail.SetOnePointCoordinates(2,-2,1.25,-1);
	PropelorTail.SetOnePointCoordinates(3,2,1.25,-1);
	PropelorTail.MovePolygonCenter(PropelorTailPin1.GetPoint(0));
	PropelorTail.ScaleSelfPolygon(0.01,1,1);
	PropelorTail.RotateSelfPolygon(X_AXIS,180);
	PropelorTail.RotateSelfPolygon(Z_AXIS,-90);
	PropelorTail.SetPolygonColor(1,1,1);
	SetOnePolygon(29, PropelorTail);

	CSquare PropelorTailBack;
	PropelorTail.SetNumberOfPoints(4);
	PropelorTail.SetOnePointCoordinates(3,2,1.25,1);
	PropelorTail.SetOnePointCoordinates(2,-2,1.25,1);
	PropelorTail.SetOnePointCoordinates(1,-2,1.25,-1);
	PropelorTail.SetOnePointCoordinates(0,2,1.25,-1);
	PropelorTail.MovePolygonCenter(PropelorTailPin1.GetPoint(0));
	PropelorTail.ScaleSelfPolygon(0.01,1,1);
	PropelorTail.RotateSelfPolygon(X_AXIS,180);
	PropelorTail.RotateSelfPolygon(Z_AXIS,-90);
	PropelorTail.SetPolygonColor(1,1,1);
	SetOnePolygon(30, PropelorTail);

	RotateSelfModel(Y_AXIS,180);
	theta_y=0;
	v=0;
	vy=0;
	double angle_in_radians = theta_y * PI / 180;
	vx=v*sin(angle_in_radians);
	vz=v*cos(angle_in_radians);
}

void CKopter::RotatePropelor(double angle)
{
	CPoint one,two;
	//Create a vector using two points (a,b,c) (d,e,f) - (d-a,e-b,f-c)
	two=_polygons_array[19].GetPoint(2);
	one=_polygons_array[19].GetPoint(0);
	double ax=two.GetCoordinate(X_AXIS)-one.GetCoordinate(X_AXIS);
	double ay=two.GetCoordinate(Y_AXIS)-one.GetCoordinate(Y_AXIS);
	double az=two.GetCoordinate(Z_AXIS)-one.GetCoordinate(Z_AXIS);
	//Normlaize the vector (dividing every component by it's length)
	double length=sqrt((ax*ax)+(ay*ay)+(az*az));
	ax=ax/length;
	ay=ay/length;
	az=az/length;
	CPoint three(ax,ay,az);
	//Calling the function
	_polygons_array[28].MovePolygonByVector(angle, three);


	CPoint _one,_two;
	//Create a vector using two points (a,b,c) (d,e,f) - (d-a,e-b,f-c)
	_two=_polygons_array[24].GetPoint(3);
	_one=_polygons_array[24].GetPoint(0);
	double _ax=_two.GetCoordinate(X_AXIS)-_one.GetCoordinate(X_AXIS);
	double _ay=_two.GetCoordinate(Y_AXIS)-_one.GetCoordinate(Y_AXIS);
	double _az=_two.GetCoordinate(Z_AXIS)-_one.GetCoordinate(Z_AXIS);
	//Normlaize the vector (dividing every component by it's length)
	double _length=sqrt((_ax*_ax)+(_ay*_ay)+(_az*_az));
	_ax=_ax/_length;
	_ay=_ay/_length;
	_az=_az/_length;
	CPoint _three(_ax,_ay,_az);
	//Calling the function
	_polygons_array[29].MovePolygonByVector(angle, _three);

	CPoint _oneNew,_twoNew;
	//Create a vector using two points (a,b,c) (d,e,f) - (d-a,e-b,f-c)
	_twoNew=_polygons_array[24].GetPoint(3);
	_oneNew=_polygons_array[24].GetPoint(0);
	double _axNew=_twoNew.GetCoordinate(X_AXIS)-_oneNew.GetCoordinate(X_AXIS);
	double _ayNew=_twoNew.GetCoordinate(Y_AXIS)-_oneNew.GetCoordinate(Y_AXIS);
	double _azNew=_twoNew.GetCoordinate(Z_AXIS)-_oneNew.GetCoordinate(Z_AXIS);
	//Normlaize the vector (dividing every component by it's length)
	double _lengthNew=sqrt((_axNew*_axNew)+(_ayNew*_ayNew)+(_azNew*_azNew));
	_axNew=_axNew/_lengthNew;
	_ayNew=_ayNew/_lengthNew;
	_azNew=_azNew/_lengthNew;
	CPoint _threeNew(_axNew,_ayNew,_azNew);
	//Calling the function
	_polygons_array[30].MovePolygonByVector(angle, _threeNew);
}
void CKopter::RotateKopterY(double angle) {
	RotateSelfModel(Y_AXIS,angle);
	theta_y+=angle;
	double angle_in_radians = theta_y * PI / 180;
	vx=v*sin(angle_in_radians);
	vz=v*cos(angle_in_radians);
}
void CKopter::MoveForward() {
	MoveModel(vx,0,vz);
}
void CKopter::Accelerate(double v0){
	v=v0;
	double angle_in_radians = theta_y * PI / 180;
	vx=v*sin(angle_in_radians);
	vz=v*cos(angle_in_radians);
}