//
//  RectGrid.h
//  Game2
//
//  Created by Stepanov Ilia on 22/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__RectGrid__
#define __Game2__RectGrid__

#include "BaseRenderable.h"
#include "RectRenderable.h"
#include <vector>

class RectGrid : public BaseRenderable
{
public:
	
	RectGrid() : BaseRenderable(), is_set(false)
	{;}
	
	void SetParams(int count_x, int count_y, float cell_size);
	
	virtual void set_shader(GLuint program);
	virtual void setup_vertexes();
	virtual void Draw();
	
	bool IsSet() { return is_set; }
	
	
private:
	
	RectRenderable rect;
	
	bool is_set;
	int count_x;
    int count_y;
    float step;
	
	GLuint shader;
};

#endif /* defined(__Game2__RectGrid__) */
