//
//  RectGrid.cpp
//  Game2
//
//  Created by Stepanov Ilia on 22/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#include "RectGrid.h"
#include "../GameEngine.h"

void RectGrid::SetParams(int count_x, int count_y, float cell_size)
{
	this->count_x = count_x;
	this->count_y = count_y;
	this->step = cell_size;
	setup_vertexes();
	if(count_x > 0 && count_y > 0 && cell_size > 0.0f)
		is_set = true;
}

void RectGrid::set_shader(GLuint program)
{
	rect.set_shader(program);
}

void RectGrid::setup_vertexes()
{
	rect.set_height(step);
	rect.set_width(step);
	rect.setup_vertexes();
	rect.SetColor(0.8f, 0.8f, 0.8f);
}

void RectGrid::Draw()
{
	for(int i = 0; i < count_x; i++)
	{
		for(int j = 0; j < count_y; j++)
		{
			if(GameEngine::get_data()->logic.GetCellPosibility(Vec2i(i, j)))
				continue;
			
			rect.coords.x = (- count_x / 2 + i) * step + step / 2;
			rect.coords.y = (- count_y / 2 + j) * step + step / 2;
			rect.Draw();
		}
	}
}