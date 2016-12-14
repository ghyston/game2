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
#include "GamePlay/PathFinder.h"

// @todo: refactoring this! Google pattern "State" and other behvior patterns
void InputProcessor::process_touch(int type, float screen_x, float screen_y)
{
	if(screen_x < 0 || screen_x > GameEngine::global_data->screen.width ||
	   screen_y < 0 || screen_y > GameEngine::global_data->screen.height)
		return;
	
	
	// This would be base code for my unwritten logging system
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
	log.append("\n");
	
	
	Vec2f world_coords = GameEngine::global_data->convert_coordinates(Vec2f(screen_x, screen_y));
	
	Vec2f map_size(
		GameEngine::get_data()->logic.getMap()->map_width,
		GameEngine::get_data()->logic.getMap()->map_height);
	
	if(world_coords.x < -map_size.x ||
	   world_coords.x > map_size.x ||
	   world_coords.y < -map_size.y ||
	   world_coords.y > map_size.y)
		return;
	
	if(type == TouchTypes::PRESS)
	{
		// @todo: here we should check gui for input
		
		// if gui is not activated, find scene object
		EntityPtr temp = find_entity(world_coords);
		if(!temp.expired())
		{
			GetCmpt(PlayerIdComponent, plr_it_cmpt, temp.lock());
			if(plr_it_cmpt->player_id != GlobalData::PLAYER_ID_1)
				return;
			
			touched_entity = temp;
			press_coords = world_coords;
			GetCmpt(PositionComponent, pos_com, touched_entity.lock());
			old_entity_coords = pos_com->position;
			return;
		}
		
		// if not, move scene:
		press_coords = Vec2f(screen_x, screen_y);
		old_cam_pos = GameEngine::global_data->camera->coords;
	}
	
	if(type == TouchTypes::RELEASE)
	{
		if (!touched_entity.expired())
		{
			GameEngine::get_renderer()->showBorderRing = false;
			
			GetCmpt(PositionComponent, pos_com, touched_entity.lock());
			Vec2f distVec = world_coords - pos_com->position;
			float dist = distVec.length();
			if(dist > GameConst::TOWER_MAX_DIST)
				distVec.length(GameConst::TOWER_MAX_DIST);
			Vec2f new_tower_coords = pos_com->position + distVec;
			
			if(dist > GameConst::TOWER_MIN_DIST)
			{
				//@todo: here would bew checking, is release coords belong to
				// tower at another player.
			
				EntityPtr tower_at_release = find_entity(new_tower_coords);
				if(!tower_at_release.expired())
				{
					GetCmpt(PlayerIdComponent, dist_plr_id_cmpt, tower_at_release.lock());
					GetCmpt(PlayerIdComponent, from_plr_id_cmpt, touched_entity.lock());
					if(dist_plr_id_cmpt->player_id != from_plr_id_cmpt->player_id)
					{
						GameEngine::global_data->logic.tower_attack(
										touched_entity, tower_at_release);
					}
				}
				else
				{
					GetCmpt(EnergyStorageComponent, enesto_cmpt, touched_entity.lock());
					
			
					if(enesto_cmpt->value > GameConst::MIN_ENERGY_TO_ACTION &&
					   GameEngine::get_data()->logic.CanBuildTower(
							pos_com->position, new_tower_coords))
					{
						enesto_cmpt->rem_energy(GameConst::TOWER_BUILD_COST);
						EntityPtr new_tower =
							EntityFabric::get_tower(touched_entity, new_tower_coords);
						GameEngine::get_data()->logic.add_tower(new_tower);
					}
				}
			}
			
		}
		else if(pathKeyPressed)
		{
			EntityPtr unit =
			GameEngine::get_data()->logic.getMap()->getFirstEntityHasCmp<PathFindComponent>();
			
			if(!unit.expired())
			{
				//if unit has already path, clear it
				GetCmpt(PathFindComponent, path_com, unit.lock());

				for(EntityIt path_it = path_com->path.begin(); path_it != path_com->path.end(); path_it++)
				{
                    path_it->lock()->mark_deleted();
				}
				path_com->path.clear();
				
				// calc new path
				std::vector<Vec2f> wayp_coords;
				GetCmpt(PositionComponent, pos_com, unit.lock());
				if(GameEngine::global_data->logic.CalcPath4Unit(
					pos_com->position, world_coords, wayp_coords))
				{
					for(auto it = wayp_coords.begin();
						it != wayp_coords.end(); it++)
					{
						EntityPtr waypoint = EntityFabric::CreateWaypoint(*it);
						GameEngine::get_data()->logic.add_entity(waypoint);
						path_com->path.push_back(waypoint);
					}
				}
			}
		}
		
		// and again, check gui, than pressed scene object.
		// if nothig, do nothing
		press_coords = Vec2f(0.0f); //@todo: not a good type of clear vec!
		touched_entity.reset();
		old_entity_coords = Vec2f(0.0f);
		new_entity_created = false;
		GameEngine::global_data->cursor.Hide();
	}
	
	if(type == TouchTypes::MOVE)
	{
		//if we get deal with entities
		if (!touched_entity.expired())
		{
			Vec2f diff = world_coords - press_coords;
			float diff_len = diff.length();
			// distance is big enough to create tower
			if(diff_len > GameConst::TOWER_MIN_DIST)
			{
				GetCmpt(PositionComponent, pos_com, touched_entity.lock());
				GameEngine::get_renderer()->border_ring_coords = pos_com->position;
				GameEngine::get_renderer()->showBorderRing = true;
				
				Vec2f cursor_pos = world_coords;
				if(diff_len > GameConst::TOWER_MAX_DIST)
				{
					diff.length(GameConst::TOWER_MAX_DIST);
					cursor_pos = pos_com->position + diff;
				}
				
				GameEngine::global_data->cursor.position = cursor_pos;
				GameEngine::global_data->cursor.Show();
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

EntityPtr InputProcessor::find_entity(Vec2f world_coords)
{
	EntityPtr result;
	EntityPtr entity = GameEngine::global_data->logic.getMap()->findClosestEntityHasCmp<TouchableComponent>(world_coords);
	
	if(!entity.expired())
	{
		GetCmpt(TouchableComponent, touch_com, entity.lock());
		GetCmpt(PositionComponent, pos_com, entity.lock());
		
		Vec2f left_bottom = pos_com->position - Vec2f(touch_com->touch_size);
		Vec2f right_top = pos_com->position + Vec2f(touch_com->touch_size);
		
		if (world_coords.x > left_bottom.x && world_coords.x < right_top.x &&
			world_coords.y > left_bottom.y && world_coords.y < right_top.y)
		{
			result = entity;
		}
	}
	
	return result;
}
