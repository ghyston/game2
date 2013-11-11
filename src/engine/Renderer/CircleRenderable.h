//
//  CircleRenderable.h
//  Game2
//
//  Created by Stepanov Ilia on 10/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__CircleRenderable__
#define __Game2__CircleRenderable__

#include "BaseRenderable.h"

class CircleRenderable : public BaseRenderable
{
public:
	
	CircleRenderable()
	{
		draw_type = GL_TRIANGLES;
	}
	
	virtual void setup_vertexes();
	
	void radius(float new_radius) { rad = new_radius; }
	
	float radius() { return rad; }
	
private:
	float rad;
	
	static const int points_count;
	
};

#endif /* defined(__Game2__CircleRenderable__) */
