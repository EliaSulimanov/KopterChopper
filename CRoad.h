#include "CModel.h"
#include "CSquare.h"

class CRoad : public CModel {
public:
	CRoad(void);
	CRoad(double scalex,double scalez);

private:
	double scale_x,scale_z;
};