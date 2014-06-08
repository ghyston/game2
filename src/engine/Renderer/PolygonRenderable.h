//
//  PolygonRenderable.h
//  Game2
//
//  Created by Stepanov Ilia on 07/06/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__PolygonRenderable__
#define __Game2__PolygonRenderable__

#include "BaseRenderable.h"

#include <vector>

// Draw convex polygons. Add vertex by clockwise!
class PolygonRenderable : public BaseRenderable
{
public:
	PolygonRenderable()
	{
		draw_type = GL_TRIANGLES;
	}
	
	virtual void setup_vertexes();
	
	void AddVertex(Vec2f vertex);
	
private:
	
	std::vector<Vec2f> points;
	
};

#endif /* defined(__Game2__PolygonRenderable__) */
