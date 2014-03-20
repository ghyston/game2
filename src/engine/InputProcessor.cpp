//
//  InputProcessor.cpp
//  Game2
//
//  Created by Stepanov Ilia on 12/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "InputProcessor.h"
#include "GameEngine.h"
#include "GamePlay/EntityFabric.h"

// @todo: refactoring this! Google pattern "State" and other behvior patterns
void InputProcessor::process_touch(int type, float screen_x, float screen_y)
{
	if(screen_x < 0 || screen_x > GameEngine::global_data->screen.width ||
	   screen_y < 0 || screen_y > GameEngine::global_data->screen.height)
		return;
	
	/*
	 This would be base code for my unwritten logging system
	 std::string log;
	std::ostringstream ss;
	
	log.append("touch_log type:");
	ss << type;
	log.append(ss.str());
	ss.clear();
	
	log.append("x: ");
	ss << screen_x;
	log.append(ss.str());
	ss.clear();

	log.append("y: ");
	ss << screen_y;
	log.append(ss.str());
	ss.clear();
	log.append("\n");*/
	
	
	Vec2f world_coords = GameEngine::global_data->convert_coordinates(Vec2f(screen_x, screen_y));
	
	if(type == TouchTypes::PRESS)
	{
		// here we should check gui for input
		
		// if gui is not activated, find scene object
		EntityPtr temp = find_entity(world_coords);
		if(temp.is_set())
		{
			GetCmpt(PlayerIdComponent, plr_it_cmpt, temp);
			if(plr_it_cmpt->player_id != GlobalData::PLAYER_ID_1)
				return;
			
			touched_entity = temp;
			press_coords = world_coords;
			GetCmpt(PositionComponent, pos_com, touched_entity);
			old_entity_coords = pos_com->position;
			return;
		}
		
		// if not, move scene:
		press_coords = Vec2f(screen_x, screen_y);
		old_cam_pos = GameEngine::global_data->camera->coords;
	}
	
	if(type == TouchTypes::RELEASE)
	{
		if (touched_entity.is_set())
		{
			GameEngine::get_renderer()->showBorderRing = false;
			
			GetCmpt(PositionComponent, pos_com, touched_entity);
			Vec2f distVec = world_coords - pos_com->position;
			float dist = distVec.length();
			
			if(dist < 0.4f)
			{
			
				//@todo: here would bew checking, is release coords belong to
				// tower at another player.
			
				EntityPtr tower_at_release = find_entity(world_coords);
				if(tower_at_release.is_set())
				{
					GetCmpt(PlayerIdComponent, dist_plr_id_cmpt, tower_at_release);
					GetCmpt(PlayerIdComponent, from_plr_id_cmpt, touched_entity);
					if(dist_plr_id_cmpt->player_id != from_plr_id_cmpt->player_id)
					{
						GameEngine::global_data->logic.tower_attack(
										touched_entity, tower_at_release);
					}
				}
				else
				{
					GetCmpt(EnergyStorageComponent, enesto_cmpt, touched_entity);
					Vec2f diff = world_coords - pos_com->position;
			
					if(diff.length() > 0.2 && enesto_cmpt->value > 60)
					{
						enesto_cmpt->rem_energy(50);
						EntityPtr new_tower =
							EntityFabric::get_tower(touched_entity, world_coords);
						GameEngine::get_data()->logic.add_tower(new_tower);
					}
				}
			}
			
		}
		
		// and again, check gui, than pressed scene object.
		// if nothig, do nothing
		press_coords = Vec2f(0.0f); //@todo: not a good type of clear vec!
		touched_entity = NULL;
		old_entity_coords = Vec2f(0.0f);
		new_entity_created = false;
		GameEngine::global_data->cursor.Hide();
	}
	
	if(type == TouchTypes::MOVE)
	{
		//if we get deal with entities
		if (touched_entity.is_set())
		{
			Vec2f diff = world_coords - press_coords;
				
			// distance is big enough, create tower
			// @todo: 50 is test value here, it shouldn't be percentage!
			if(diff.length() > 0.2/* && enesto_cmpt->value > 50*/)
			{
				GameEngine::global_data->cursor.position = world_coords;
				GameEngine::global_data->cursor.Show();
				
				GetCmpt(PositionComponent, pos_com, touched_entity);
				GameEngine::get_renderer()->border_ring_coords = pos_com->position;
				GameEngine::get_renderer()->showBorderRing = true;
			}
			return;
		}
		
		// @todo: Vec(0.0f.. is it not goood!
		if(press_coords.x == 0.0f && press_coords.y == 0.0f)
			return;
		
		Vec2f screen_diff = (Vec2f(screen_x, screen_y) - press_coords);
		screen_diff.x *= 2.0 / GameEngine::global_data->screen.width;
		screen_diff.y *= - 2.0 * GameEngine::global_data->screen.ratio /
			GameEngine::global_data->screen.height;
		
		GameEngine::global_data->camera->coords =
			old_cam_pos - screen_diff;
	}
}

// @todo: loop throw all entities, not good!
EntityPtr InputProcessor::find_entity(Vec2f world_coords)
{
	Entities& entities = GameEngine::global_data->logic.
		get_entities_by_coords(world_coords);
	EntityIt it = entities.begin();
	while(it != entities.end())
	{
		if(!HasCmpt(TouchableComponent, (*it)))
		{
			it++;
			continue;
		}
		
		GetCmpt(TouchableComponent, touch_com, (*it));
		GetCmpt(PositionComponent, pos_com, (*it));
		
		Vec2f left_bottom = pos_com->position - Vec2f(touch_com->touch_size);
		Vec2f right_top = pos_com->position + Vec2f(touch_com->touch_size);
		
		if (world_coords.x > left_bottom.x && world_coords.x < right_top.x &&
			world_coords.y > left_bottom.y && world_coords.y < right_top.y)
		{
			//touched_entity = it->second;
			return (*it);
		}
		it++;
	}
	return EntityPtr(NULL);
}