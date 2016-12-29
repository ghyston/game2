//
//  AISystem.cpp
//  Game2
//
//  Created by Stepanov Ilia on 24/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "AISystem.h"

void AISystem::pre_step()
{
	if(GameEngine::global_data->aiLogic.newTowerBuilded)
	{
		//@todo: do it by aiLogic
		GameEngine::global_data->aiLogic.newTowerBuilded = false;
		state = ENEMY_SEARCHING;
	}
	
	
	// Reset destination
	if(state == ENEMY_DEAD)
		state = ENEMY_SEARCHING;
	if(state == ENEMY_SEARCHING)
	{
		destination_to_closest_tower = 10000;
		path.clear();
	}
	
	
		
	//	target = GenerateRandomTarget();
}

/*Vec2f AISystem::GenerateRandomTarget()
{
	Vec2i map_size, result;
	Map* map = GameEngine::get_data()->logic.getMap();
	map_size.x = map->pass_map.getWidth();
	map_size.y = map->pass_map.getHeight();
	
	Vec2i tower_size = ceil(GameConst::TOWER_SIZE / map->pass_map.getCellSize());
	
	do
	{
		result.x = rand() % (map_size.x * 2 + 1) - map_size.x;
		result.y = rand() % (map_size.y * 2 + 1) - map_size.y;
	}
	while (!map->pass_map.CheckCellsPass(result, result + tower_size));
	
	destination_to_closest_tower = 10000; //@todo: define infinity?
	
	return map->pass_map.getCoordsByIndex(result);
}*/


void AISystem::post_step()
{
	if(state == ENEMY_SEARCHING)
	{
		if(closest_tower.expired())
			return;
	
		GetCmpt(PositionComponent, my_pos_com, closest_tower.lock());
		GetCmpt(PositionComponent, enemy_pos_com, enemy_tower.lock());
		
		Entities entList;
		entList.push_back(closest_tower);
		entList.push_back(enemy_tower);
		
		GameEngine::get_data()->logic.CalcPath4Tower(my_pos_com->position, enemy_pos_com->position, path, entList);
		
		GetCmpt(AiComponent, ai_com, closest_tower.lock());
		ai_com->is_head = true;
		
		bool pathEmpty = path.empty();
		if(!pathEmpty)
			path.pop_back(); //remove tower-target
		
		pathEmpty = path.empty();
		
		pathIt = path.begin();
		pathIt++;
		
		state = (path.empty()) ? ENEMY_ATTAKING : BUILD_TO_ENEMY;
	}
}

void AISystem::update(EntityPtr entity)
{
	if(!HasCmpt(PlayerIdComponent, entity.lock()))
		return;
	
	GetCmpt(PlayerIdComponent, plr_id_cmp, entity.lock());
	if(plr_id_cmp->player_id == GlobalData::PLAYER_ID_1)
		return;
	
	//for towers only
	if(!HasCmpt(EnergyStorageComponent, entity.lock()))
		return;

	// find closest enemy tower
	//if(!target_set)
	if(state == ENEMY_SEARCHING)
	{
		GetCmpt(PositionComponent, pos_com, entity.lock());
		EntityPtr enemy_tower_temp = GameEngine::get_data()->logic.getMap()->getClosestEnemyTower(pos_com->position);
		GetCmpt(PositionComponent, enemy_pos_com, enemy_tower_temp.lock());
		
		Vec2f dist = pos_com->position - enemy_pos_com->position;
		if(dist.length() < destination_to_closest_tower)
		{
			enemy_tower = enemy_tower_temp;
			closest_tower = entity;
			destination_to_closest_tower = dist.length();
		}
		return;
	}
	else if(state == ENEMY_DEAD)
	{
		// @todo: clear here some info
		GetCmpt(AiComponent, ai_com, entity.lock());
		ai_com->is_head = false;
		
	}
	
		
	// All other states are to head towers only!
	GetCmpt(AiComponent, ai_com, entity.lock());
	if(!ai_com->is_head)
			return;
		
	//if(!enemyNearby)
	if(state == BUILD_TO_ENEMY)
	{
		//jft
		for(auto it = path.begin(); it != path.end(); it++)
		{
			GameEngine::renderer->draw_small_rect(*it);
		}
		
		GetCmpt(EnergyStorageComponent, enesto_cmpt, entity.lock());
		if(enesto_cmpt->value < GameConst::MIN_ENERGY_TO_ACTION)
			return;
	
		enesto_cmpt->rem_energy(GameConst::TOWER_BUILD_COST);
		EntityPtr new_tower =
			EntityFabric::get_tower(entity, *pathIt);
		GetCmpt(AiComponent, new_ai_com, new_tower.lock());
		new_ai_com->is_head = true;
		GameEngine::get_data()->logic.add_tower(new_tower);
		ai_com->is_head = false;
	
		pathIt++;
		if(pathIt == path.end())
		{
			state = ENEMY_ATTAKING;
		}
	}
	else
	if(state == ENEMY_ATTAKING)
	{
		if(enemy_tower.expired()) //@todo: is this necessary?
		{
			state = ENEMY_DEAD;
			
		}
		
		GameEngine::get_data()->logic.tower_attack(entity, enemy_tower);
	}
	
	
	return;
	
	// @todo: It's very slow algorythm! Y need to proceed it on new tower build only or on new enemy tower on range build.
/*	DetectTarget(entity);
	
	GetCmpt(PositionComponent, pos_cmpt, entity);
	GetCmpt(TargetComponent, targt_cmpt, entity);
	GetCmpt(PositionComponent, target_pos_cmpt, targt_cmpt->target);
	
	Vec2f to_target = pos_cmpt->position - target_pos_cmpt->position;
	float dist = to_target.length();
	if(!targt_cmpt->target_enemy)
	{
		GetCmpt(EnergyGeneratorComponent, targt_gen_cmpt, targt_cmpt->target);
		dist -= targt_gen_cmpt->radius;
	}
	
	//@todo: move to constants! 0.2 - attack\build tower distance!
	if(dist < 0.2f)
	{
		if(targt_cmpt->target_enemy)
		{
			//@todo: attack!
			
		}
		else
		{
			// Build new tower
			GetCmpt(EnergyStorageComponent, enesto_cmpt, entity);
			if(enesto_cmpt->value < 75)
				return;
			
		//	if(dist < 0.3)
			
			
		}
	}*/
}

/*void AISystem::DetectTarget(EntityPtr entity)
{
	// @todo: it's too cost to check it here!
	if(!HasCmpt(TargetComponent, entity))
	{
		TargetComponent* target_comp = new TargetComponent();
		entity->add_component(target_comp);
	}
	
	//@todo: find only entities in rad.
	float closest_enemy_dist = 10000;
	EntityPtr closest_enemy;
	
	float closest_gen_dist = 10000;
	EntityPtr closest_gen;
	
	GetCmpt(PositionComponent, my_pos_cmpt, entity);
	Vec2f my_pos = my_pos_cmpt->position;
	
	Entities entities;
	//= GameEngine::get_data()->logic.get.get_entities();
	for(EntityIt it = entities.begin(); it != entities.end(); it++)
	{
		// Todo: check enemy;
		if(HasCmpt(PlayerIdComponent, it->get()) &&
		   HasCmpt(EnergyStorageComponent, it->get()))
		{
			GetCmpt(PlayerIdComponent, plId_cmpt, it->get());
			if(plId_cmpt->player_id == GlobalData::PLAYER_ID_1)
				continue;
			
			GetCmpt(PositionComponent, pos_cmpt, it->get());
			Vec2f distance = pos_cmpt->position - my_pos;
			if(distance.length() < closest_enemy_dist)
			{
				closest_enemy_dist = distance.length();
				closest_enemy = it->get();
			}
			continue;
		}
		
		// Find closest generator.
		if(HasCmpt(EnergyGeneratorComponent, it->get()))
		{
			GetCmpt(PositionComponent, pos_cmpt, it->get());
			Vec2f distance = pos_cmpt->position - my_pos;
			if(distance.length() < closest_gen_dist)
			{
				closest_gen_dist = distance.length();
				closest_gen = it->get();
			}
		}
	}
	
	if(closest_enemy_dist < closest_gen_dist)
	{
		GetCmpt(TargetComponent, targ_cmpt, entity);
		targ_cmpt->target = closest_enemy;
		targ_cmpt->target_enemy = true;
	}
	else
	{
		GetCmpt(TargetComponent, targ_cmpt, entity);
		targ_cmpt->target = closest_gen;
		targ_cmpt->target_enemy = false;
	}
}*/

/*EntityPtr AISystem::findClosestEnemy(EntityPtr entity)
{
	float closest_enemy_dist = 10000;
	EntityPtr closest_enemy;
		
	GetCmpt(PositionComponent, my_pos_cmpt, entity);
	Vec2f my_pos = my_pos_cmpt->position;
	
	Entities& entities = GameEngine::get_data()->logic.get_entities_by_coords(my_pos);
	for(EntityIt it = entities.begin(); it != entities.end(); it++)
	{
		// Todo: check enemy;
		if(HasCmpt(PlayerIdComponent, it->get()) &&
		   HasCmpt(EnergyStorageComponent, it->get()))
		{
			GetCmpt(PlayerIdComponent, plId_cmpt, it->get());
			if(plId_cmpt->player_id == GlobalData::PLAYER_ID_2)
				continue;
			
			GetCmpt(PositionComponent, pos_cmpt, it->get());
			Vec2f distance = pos_cmpt->position - my_pos;
			if(distance.length() < closest_enemy_dist)
			{
				closest_enemy_dist = distance.length();
				closest_enemy = it->get();
			}
			continue;
		}
	}
	
	if(closest_enemy_dist > 0.3f) //@todo: remove hardcode!
	{
		closest_enemy.set(NULL);
	}
	
	return closest_enemy;
}*/

/*void AISystem::BuildRandomTower(EntityPtr entity)
{
	// Not enouth energy
	GetCmpt(EnergyStorageComponent, enesto_cmpt, entity);
	if(enesto_cmpt->value < 75)
		return;
	
	GetCmpt(PositionComponent, pos_com, entity)
	
	float rad = (rand() % 100) * 0.5 / 100.0f + 0.15f;
	float angle = (rand() % 200) / 100.0f;
	Vec2f coords (rad * cos(angle * M_PI), rad * sin(angle * M_PI));
	
	Vec2f new_coords = pos_com->position + coords;
	if(!GameEngine::get_data()->logic.CanBuildTower(pos_com->position, new_coords))
		return;
	
	enesto_cmpt->rem_energy(70);
	EntityPtr new_tower =
	EntityFabric::get_tower(entity, new_coords);
	GameEngine::get_data()->logic.add_tower(new_tower);

}*/
