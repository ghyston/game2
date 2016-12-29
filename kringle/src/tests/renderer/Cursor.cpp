//
//  Cursor.cpp
//  Game2
//
//  Created by Stepanov Ilia on 17/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "Cursor.h"
#include "GameEngine.h"

void Cursor::Draw()
{
	if(!show)
		return;
	
	GameEngine::renderer->draw_ring(position);
}