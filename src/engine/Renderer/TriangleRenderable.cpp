//
//  TriangleRenderable.cpp
//  Game2
//
//  Created by Stepanov Ilia on 23/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#include "TriangleRenderable.h"

void TriangleRenderable::setup_vertexes()
{
	vertexes_count = 3;
	vertexes = new float[vertexes_count * 2];
	
	vertexes[0] = rad;
	vertexes[1] = 0.0f;
	
	vertexes[2] = -rad / 2;
	vertexes[3] = -rad / 2;
	
	vertexes[4] = -rad / 2;
	vertexes[5] = rad / 2;


}