#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Matrix4f.h"

class Camera
{
public:

	Camera();
	
	~Camera();
	
	Matrix4f* ortho;
	
	void setup_ortho(
		float left, float right, 
		float bottom, float top, 
		float near, float far);

};

#endif //__CAMERA_H__
