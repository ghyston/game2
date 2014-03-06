//
//  RingRenderable.cpp
//  Game2
//
//  Created by Stepanov Ilia on 17/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "RingRenderable.h"
#include <math.h>

const int RingRenderable::points_count = 32;

void RingRenderable::setup_vertexes()
{
	vertexes = new float[points_count * 2];
	float angle = 2.0f / (float)points_count;
	for(int i = 0; i < points_count; i++)
	{
		vertexes[i * 2 + 0] = rad * cos(angle * i * M_PI);
		vertexes[i * 2 + 1] = rad * sin(angle * i * M_PI);
	}
	vertexes_count = points_count;
}