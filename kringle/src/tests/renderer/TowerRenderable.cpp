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
	Color3f back_color(0.1f, 0.2f, 0.3f);
    back->SetColor(back_color);
	
	front = new RectRenderable(size, size);
    front->set_shader(this->shader);
	Color3f front_color(0.0f, 0.3f, 0.9f);
    front->SetColor(front_color);
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