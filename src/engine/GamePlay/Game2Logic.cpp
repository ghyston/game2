//
//  Game2Logic.cpp
//  Game2
//
//  Created by Stepanov Ilia on 05/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "Game2Logic.h"
#include "Systems/RenderSystem.h"
#include "Systems/MoveSystem.h"
#include "Systems/TargetEnergySystem.h"
#include "Systems/CollisionSystem.h"
#include "Systems/EnergyCreatorSystem.h"
#include "EnergyBalanceSystem.h" // @todo: wtf??
#include "EntityFabric.h"


void Game2Logic::start()
{
	add_system(new RenderSystem());
	add_system(new MoveSystem());
	//add_system(new CollisionSystem());
	add_system(new TargetEnergySystem());
	add_system(new EnergyBalanceSystem());
	add_system(new EnergyGeneratorSystem());
}

void Game2Logic::stop()
{
	//@todo: remove all systems!
}

void Game2Logic::add_tower(Entity * tower)
{
	GameLogic::add_entity(tower);
	
	//setup player id
	GetCmpt(NodeComponent, node_com, tower);
	if(node_com->parent != NULL)
	{
		GetCmpt(PlayerIdComponent, parent_plr_id_cmpt, node_com->parent);
		GetCmpt(PlayerIdComponent, self_plr_id_cmpt, tower);
		self_plr_id_cmpt->player_id = parent_plr_id_cmpt->player_id;
	}
	
	//Find energy generator nearby
	EntityIt it = entities.begin();
	while (it != entities.end())
	{
		if(!HasCmpt(EnergyGeneratorComponent, it->second))
		{
			it++;
			continue;
		}
		
		GetCmpt(PositionComponent, generator_pos_com, it->second);
		GetCmpt(EnergyGeneratorComponent, gen_com, it->second);
		GetCmpt(PositionComponent, pos_com, tower);
		
		Vec2f diff = generator_pos_com->position - pos_com->position;
		
		if(gen_com->radius > diff.length())
		{
			gen_com->towers.push_back(tower);
			break;
		}
		it++;
	}
}

void Game2Logic::add_energy(Entity * energy, Entity * generator)
{
	GetCmpt(TargetComponent, tar_cmpt, energy);
	GetCmpt(EnergyGeneratorComponent, engen_cmpt, generator);
	GetCmpt(PositionComponent, energy_pos_cmpt, energy);
	
	if(engen_cmpt->towers.size() == 0)
		return;
	
	float min_dist = engen_cmpt->radius;
	std::vector<Entity*>::iterator it = engen_cmpt->towers.begin();
	Entity * closest_tower = *it;
	while (it != engen_cmpt->towers.end())
	{
		GetCmpt(PositionComponent, tower_pos_com, (*it));
			
		Vec2f dist = energy_pos_cmpt->position - tower_pos_com->position;
			
		if(dist.length() < min_dist)
		{
			closest_tower = *it;
			min_dist = dist.length();
		}
		it++;
	}
	
	tar_cmpt->target.pointer = closest_tower;
	GameLogic::add_entity(energy);
}

void Game2Logic::tower_attack(Entity * from, Entity * to)
{
	GetCmpt(EnergyStorageComponent, from_enesto_cmpt, from);
	GetCmpt(PositionComponent, from_pos_cmpt, from);
	// @todo: move constants to one game_disdock header file!
	// 30 - min limit for attack posibility
	if(from_enesto_cmpt->value > 30)
	{
		// 10 - count energys, that would attack enemy tower
		from_enesto_cmpt->value -= 10;
		Entity * energy;
		for(int i = 0; i < 10; i++)
		{
			energy = EntityFabric::create_energy(from_pos_cmpt->position);
			GetCmpt(TargetComponent, targ_cmpt, energy);
			targ_cmpt->target.pointer = to;
			targ_cmpt->target_enemy = true;
			add_entity(energy);
		}
	}
	
	
	
	
	
	
	
	
	
}

