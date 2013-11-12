//
//  InputProcessor.cpp
//  Game2
//
//  Created by Stepanov Ilia on 12/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "InputProcessor.h"
#include "GameEngine.h"
#include "GamePlay/Components.h"

void InputProcessor::process_touch(int type, float screen_x, float screen_y)
{
	Vec2f world_coords = GameEngine::global_data->convert_coordinates(Vec2f(screen_x, screen_y));
	
	if(type == TouchTypes::PRESS)
	{
		// here we should check gui for input
		// in gui is not activated, find scene object
		// if not, move scene:
		
		Entity * temp = find_entity(world_coords);
		if(temp != NULL)
		{
			touched_entity = temp;
			press_coords = world_coords;
			GetCmpt(PositionComponent, pos_com, touched_entity);
			old_entity_coords = pos_com->position;
			return;
		}
		
		press_coords = world_coords;
		old_cam_pos = GameEngine::global_data->camera->coords;
	}
	
	if(type == TouchTypes::RELEASE)
	{
		// and again, check gui, than pressed scene object.
		// if nothig, do nothing
		press_coords = Vec2f(0.0f); //@todo: not a good type of clear vec!
		touched_entity = NULL;
		old_entity_coords = Vec2f(0.0f);
	}
	
	if(type == TouchTypes::MOVE)
	{
		// if nothing, do nothing
		
		if (touched_entity != NULL)
		{
			GetCmpt(PositionComponent, pos_com, touched_entity);
			pos_com->position = old_entity_coords + (world_coords - press_coords);
			
		}
		
		// @todo: Vec(0.0f.. is it not goood!
		if(press_coords.x == 0.0f && press_coords.y == 0.0f)
			return;
		
		GameEngine::global_data->camera->coords =
			old_cam_pos + (world_coords - press_coords);
	}
}

// @todo: loop throw all entities, not good!
Entity * InputProcessor::find_entity(Vec2f world_coords)
{
	Entities& entities = GameEngine::global_data->logic.get_entities();
	EntityIt it = entities.begin();
	while(it != entities.end())
	{
		if(!HasCmpt(TouchableComponent, it->second))
		{
			it++;
			continue;
		}
		
		GetCmpt(TouchableComponent, touch_com, it->second);
		GetCmpt(PositionComponent, pos_com, it->second);
		
		Vec2f left_bottom = pos_com->position - Vec2f(touch_com->touch_size);
		Vec2f right_top = pos_com->position + Vec2f(touch_com->touch_size);
		
		if (world_coords.x > left_bottom.x && world_coords.x < right_top.x &&
			world_coords.y > left_bottom.y && world_coords.y < right_top.y)
		{
			touched_entity = it->second;
			return it->second;
		}
		it++;
	}
	return NULL;
}