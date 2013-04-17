#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "HysVec2f.h"

class Camera
{
public:
	HysVec2f pos;
	float zoom;
	float ratio;

	Camera() : pos(0.0f, 0.0f), zoom(1.0f)
	{}

	void set_ratio(float _ratio)
	{
		ratio = _ratio;
	}
};

#endif //__CAMERA_H__