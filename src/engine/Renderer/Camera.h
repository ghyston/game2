#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "../Common/Vector2f.h"

class Camera
{
public:

	Vec2f coords;
	float zoom_koeff;

	Camera(float x = 0.0f, float y = 0.0f, float zoom = 1.0f) :
	coords(x, y), zoom_koeff(zoom)
	{
		;
	}

	void move(Vec2f diff);

	void zoom(float new_val);

};

#endif //__CAMERA_H__
