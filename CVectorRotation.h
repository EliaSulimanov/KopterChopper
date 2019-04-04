#include "CPoint.h"

class CVectorRotation{
	public:
		CPoint CVectorRotation::GetNewRotatedPoint(float x,float y,float z,float u,float v,float w,float angle);
		void CVectorRotation::multiplyMatrix();
		void CVectorRotation::setUpRotationMatrix(float angle, float u, float v, float w);
		CVectorRotation::CVectorRotation(){};
private:
};