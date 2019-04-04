#include "CRoad.h"
#include "CSquare.h"

CRoad::CRoad(void)
{
	SetNumberOfPolygons(1);

	CSquare square;
	scale_x=1;
	scale_z=1;
	square.RotateSelfPolygon(X_AXIS,-90);
	square.ScaleSelfPolygon(X_AXIS,scale_x);
	square.ScaleSelfPolygon(Z_AXIS,scale_z);
	square.SetPolygonColor(0.1,0.1,0.1);
	SetOnePolygon(0,square);
}

CRoad::CRoad(double scalex, double scalez) {
	
	SetNumberOfPolygons(1);
	
	CSquare square;
	scale_x=scalex;
	scale_z=scalez;
	square.RotateSelfPolygon(X_AXIS,-90);
	square.ScaleSelfPolygon(X_AXIS,scale_x);
	square.ScaleSelfPolygon(Z_AXIS,scale_z);
	square.SetPolygonColor(0.3,0.3,0.3);
	SetOnePolygon(0,square);
}


