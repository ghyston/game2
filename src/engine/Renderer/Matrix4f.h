#ifndef __MATRIX_4F_H__
#define __MATRIX_4F_H__

#include <math.h>

// Pre-calculated value of PI / 180.
#define kPI180   0.017453
 
// Pre-calculated value of 180 / PI.
#define k180PI  57.295780
 
// Converts degrees to radians.
#define degreesToRadians(x) (x * kPI180)
 
// Converts radians to degrees.
#define radiansToDegrees(x) (x * k180PI)

class Matrix4f
{
private:

	//values
	float val[16];
	
public:
	void Identity();
 
	void Translate(float x, float y, float z);
 
	void Scale(float sx, float sy, float sz);
 
	void RotateX(float degrees);
 
	void RotateY(float degrees);
 
	void RotateZ(float degrees);
	
	float& operator [] (int index)
	{
		//TODO: add assert index range here!
		return val[index];
	}

};

void matrixMultiply(Matrix4f& m1, Matrix4f& m2, Matrix4f& result);

#endif //__MATRIX_4F_H__