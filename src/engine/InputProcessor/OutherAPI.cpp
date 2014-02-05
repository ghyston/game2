//
//  OutherAPI.cpp
//  Game2
//
//  Created by Stepanov Ilia on 05/02/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#include "OutherAPI.h"
#include "../GameEngine.h"
#include "../Common/Vector2f.h"

void OutherAPI::MoveWorld(float diff_x, float diff_y)
{
	/*Vec2f screen_diff = (Vec2f(screen_x, screen_y) - press_coords);
	screen_diff.x *= 2.0 / GameEngine::global_data->screen.width;
	screen_diff.y *= - 2.0 * GameEngine::global_data->screen.ratio /
	GameEngine::global_data->screen.height;
	
	GameEngine::global_data->camera->coords =
	old_cam_pos - screen_diff;*/
	
	
	GameEngine::global_data->camera->coords.x = diff_x;
	GameEngine::global_data->camera->coords.y = diff_y;
}