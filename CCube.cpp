#include "CCube.h"
#include "CSquare.h"

CCube::CCube(void)
{
	SetNumberOfPolygons(6);

	CSquare square_in_cube;
	
	square_in_cube.RotatePolygon(Y_AXIS, 180);
	square_in_cube.MovePolygonCenter(0.5, 0.5, 0);
	square_in_cube.SetPolygonColor(0, 0, 0);
	SetOnePolygon(0, square_in_cube);

	square_in_cube.RotatePolygon(Y_AXIS, 90);
	square_in_cube.MovePolygonCenter(0, 0.5, 0.5);
	square_in_cube.SetPolygonColor(1, 0, 0);
	SetOnePolygon(1, square_in_cube);

	square_in_cube.RotatePolygon(Y_AXIS, 90);
	square_in_cube.MovePolygonCenter(0.5, 0.5, 1);
	square_in_cube.SetPolygonColor(1, 0, 1);
	SetOnePolygon(2, square_in_cube);

	square_in_cube.RotatePolygon(Y_AXIS, 90);
	square_in_cube.MovePolygonCenter(1, 0.5, 0.5);
	square_in_cube.SetPolygonColor(1, 1, 0);
	SetOnePolygon(3, square_in_cube);

	square_in_cube.RotatePolygon(Z_AXIS, 90);
	square_in_cube.MovePolygonCenter(0.5, 1, 0.5);
	square_in_cube.SetPolygonColor(1, 1, 1);
	SetOnePolygon(4, square_in_cube);
		
	square_in_cube.RotatePolygon(Z_AXIS, 180);
	square_in_cube.MovePolygonCenter(0.5, 0, 0.5);
	square_in_cube.SetPolygonColor(1, 0.5, 1);
	SetOnePolygon(5, square_in_cube);
}

