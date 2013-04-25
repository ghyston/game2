#ifndef __SCENE_OBJECT_H__
#define __SCENE_OBJECT_H__

#include "Vector2f.h"

class SceneObject
{
public:

	float vertex[8];
	
	Vec2f coords;
	
	float angle;
	
	const float* get_vertex() const
	{
		return &vertex[0];
	}
};

#endif //__SCENE_OBJECT_H__