//
//  RingRenderable.h
//  Game2
//
//  Created by Stepanov Ilia on 17/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__RingRenderable__
#define __Game2__RingRenderable__

#include "BaseRenderable.h"

class RingRenderable : public BaseRenderable
{
public:
	
	RingRenderable ()
	{
		draw_type = GL_LINE_LOOP;
	}
	
	virtual void setup_vertexes();
	
	void radius(float new_radius) { rad = new_radius; }
	
	float radius() { return rad; }
	
private:
	float rad;
	
	static const int points_count;
};

#endif /* defined(__Game2__RingRenderable__) */
