//
//  CircleRenderable.cpp
//  Game2
//
//  Created by Stepanov Ilia on 10/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "CircleRenderable.h"
#include <math.h>

const int CircleRenderable::points_count = 32;

void CircleRenderable::setup_vertexes()
{
	vertexes = new float[points_count * 3 * 2];
	float angle = 2.0f / (float)points_count;
	for(int i = 0; i < points_count; i++)
	{
		vertexes[i * 3 * 2] = 0.0f;
		vertexes[i * 3 * 2 + 1] = 0.0f;
		
		vertexes[i * 3 * 2 + 2] = rad * __cospi(angle * i);
		vertexes[i * 3 * 2 + 3] = rad * __sinpi(angle * i);
		
		vertexes[i * 3 * 2 + 4] = rad * __cospi(angle * (i + 1));
		vertexes[i * 3 * 2 + 5] = rad * __sinpi(angle * (i + 1));
	}
	vertexes_count = points_count * 3;
}