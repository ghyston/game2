//
//  TriangleRenderable.h
//  Game2
//
//  Created by Stepanov Ilia on 23/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__TriangleRenderable__
#define __Game2__TriangleRenderable__

#include "BaseRenderable.h"

class TriangleRenderable : public BaseRenderable
{
public:
	
	TriangleRenderable ()
	{
		draw_type = GL_LINE_LOOP;
	}
	
	virtual void setup_vertexes();
	
	void radius(float new_radius) { rad = new_radius; }
	
	float radius() { return rad; }
	
private:
	float rad;
	
};

#endif /* defined(__Game2__TriangleRenderable__) */
