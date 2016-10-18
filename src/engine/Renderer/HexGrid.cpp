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
	
	vertexes[0] = hS;
	vertexes[1] = 0;
	
	vertexes[2] = hS * 3;
	vertexes[3] = 0;
	
	vertexes[4] = hS * 4;
	vertexes[5] = sr3 * hS;
	
	vertexes[6] = hS * 3;
	vertexes[7] = sr3 * hS * 2;
	
	vertexes[8] = hS;
	vertexes[9] = sr3 * hS * 2;
	
	vertexes[10] = 0;
	vertexes[11] = sr3 * hS;
	
}
