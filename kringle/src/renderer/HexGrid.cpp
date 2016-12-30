//
//  HexGrid.cpp
//  Game2
//
//  Created by Stepanov Ilia on 17/10/2016.
//  Copyright © 2016 Stepanov Ilia. All rights reserved.
//

#include "HexGrid.h"

void HexGrid::setup_vertexes()
{
	vertexes = new float [vertexes_count * 2];
	
	float hS = _side / 2; // half side
	float sr3 = 1.732f; // sqrt(3)
	
	for(int y = 0; y < _h; y++)
	{
		for(int x = 0; x < _w; x++)
		{
			int index = (y * _w + x) * 6 * 2;
			float xOff = x * _side * 1.5;
			float yOff = y * sr3 * hS * 2 + ((x % 2 == 0) ? 0 : sr3 * hS);
			
			vertexes[index + 0] = hS + xOff;
			vertexes[index + 1] = 0 + yOff;
			
			vertexes[index + 2] = hS * 3 + xOff;
			vertexes[index + 3] = 0 + yOff;
			
			vertexes[index + 4] = hS * 4 + xOff;
			vertexes[index + 5] = sr3 * hS + yOff;
			
			vertexes[index + 6] = hS * 3 + xOff;
			vertexes[index + 7] = sr3 * hS * 2 + yOff;
			
			vertexes[index + 8] = hS + xOff;
			vertexes[index + 9] = sr3 * hS * 2 + yOff;
			
			vertexes[index + 10] = 0 + xOff;
			vertexes[index + 11] = sr3 * hS + yOff;
			
		}
	}
}
