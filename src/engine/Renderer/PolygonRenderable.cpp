//
//  PolygonRenderable.cpp
//  Game2
//
//  Created by Stepanov Ilia on 07/06/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#include "PolygonRenderable.h"


void PolygonRenderable::setup_vertexes()
{
	int points_count = (int)points.size();
	
	if(points_count < 3)
		return;
	
	vertexes = new float[points_count * 3 * 2];
	for(int i = 1; i < points_count - 1; i++)
	{
		vertexes[(i - 1) * 3 * 2] = points[0].x;
		vertexes[(i - 1) * 3 * 2 + 1] = points[0].y;
		
		vertexes[(i - 1) * 3 * 2 + 2] = points[i].x;
		vertexes[(i - 1) * 3 * 2 + 3] = points[i].y;
		
		vertexes[(i - 1) * 3 * 2 + 4] = points[i + 1].x;
		vertexes[(i - 1) * 3 * 2 + 5] = points[i + 1].y;
	}
	
	vertexes_count = points_count * 3;
}

void PolygonRenderable::AddVertex(Vec2f vertex)
{
	points.push_back(vertex);
}