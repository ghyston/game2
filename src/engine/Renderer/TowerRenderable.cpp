//
//  TowerRenderable.cpp
//  Game2
//
//  Created by Stepanov Ilia on 04/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "TowerRenderable.h"

void TowerRenderable::Init()
{
	back = new RectRenderable(size, size);
    back->setup_vertexes();
    back->set_shader(this->shader);
    back->color[0] = 0.1f;
	back->color[1] = 0.2f;
	back->color[2] = 0.3f;
	
	front = new RectRenderable(size, size);
    front->set_shader(this->shader);
    front->color[0] = 0.0f;
	front->color[1] = 0.3f;
	front->color[2] = 0.9f;
}

void TowerRenderable::setup_vertexes()
{;}

void TowerRenderable::Draw()
{
	back->coords = coords;
	front->coords.x = coords.x;
	front->coords.y = coords.y - (1.0f - energy) * size / 2;
	front->set_height(size * energy);
	front->delete_vertexes();
	front->setup_vertexes(); //@todo: do it by shader!
	back->Draw();
	front->Draw();
}