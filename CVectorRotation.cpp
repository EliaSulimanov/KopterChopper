#include <iostream>
#include <cmath> 

#include "CVectorRotation.h"
 
using namespace std; 
 
typedef struct {
    float x;
    float y;
    float z;
}Point;
Point points; 
 
float _rotationMatrix[4][4];
float _inputMatrix[4][1] = {0.0, 0.0, 0.0, 0.0};
float _outputMatrix[4][1] = {0.0, 0.0, 0.0, 0.0}; 
 
CPoint CVectorRotation::GetNewRotatedPoint(float x,float y,float z,float u,float v,float w,float angle){
	_inputMatrix[0][0] = x;
    _inputMatrix[1][0] = y;
    _inputMatrix[2][0] = z;
    _inputMatrix[3][0] = 1.0; 
 
    setUpRotationMatrix(angle, u, v, w);
    multiplyMatrix();
	return CPoint(_outputMatrix[0][0],_outputMatrix[1][0],_outputMatrix[2][0]);
} 
 
void CVectorRotation::multiplyMatrix()
{
    for(int i = 0; i < 4; i++ ){
        for(int j = 0; j < 1; j++){
            _outputMatrix[i][j] = 0;
            for(int k = 0; k < 4; k++){
                _outputMatrix[i][j] += _rotationMatrix[i][k] * _inputMatrix[k][j];
            }
        }
    }
}
void CVectorRotation::setUpRotationMatrix(float angle, float u, float v, float w)
{
    float L = (u*u + v * v + w * w);
    angle = angle * 3.14 / 180.0;
    float u2 = u * u;
    float v2 = v * v;
    float w2 = w * w; 
 
    _rotationMatrix[0][0] = (u2 + (v2 + w2) * cos(angle)) / L;
    _rotationMatrix[0][1] = (u * v * (1 - cos(angle)) - w * sqrt(L) * sin(angle)) / L;
    _rotationMatrix[0][2] = (u * w * (1 - cos(angle)) + v * sqrt(L) * sin(angle)) / L;
    _rotationMatrix[0][3] = 0.0; 
 
    _rotationMatrix[1][0] = (u * v * (1 - cos(angle)) + w * sqrt(L) * sin(angle)) / L;
    _rotationMatrix[1][1] = (v2 + (u2 + w2) * cos(angle)) / L;
    _rotationMatrix[1][2] = (v * w * (1 - cos(angle)) - u * sqrt(L) * sin(angle)) / L;
    _rotationMatrix[1][3] = 0.0; 
 
    _rotationMatrix[2][0] = (u * w * (1 - cos(angle)) - v * sqrt(L) * sin(angle)) / L;
    _rotationMatrix[2][1] = (v * w * (1 - cos(angle)) + u * sqrt(L) * sin(angle)) / L;
    _rotationMatrix[2][2] = (w2 + (u2 + v2) * cos(angle)) / L;
    _rotationMatrix[2][3] = 0.0; 
 
    _rotationMatrix[3][0] = 0.0;
    _rotationMatrix[3][1] = 0.0;
    _rotationMatrix[3][2] = 0.0;
    _rotationMatrix[3][3] = 1.0;
} 
 