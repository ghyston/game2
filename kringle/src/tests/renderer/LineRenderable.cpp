//
//  LineRenderable.cpp
//  Game2
//
//  Created by Stepanov Ilia on 10/15/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "LineRenderable.h"

void LineRenderable::setup_vertexes()
{
    vertexes[0] = start.x;
	vertexes[1] = start.y;
    
	vertexes[2] = end.x;
	vertexes[3] = end.y;
}

void LineRenderable::Draw()
{
    BaseRenderable::Draw();
}