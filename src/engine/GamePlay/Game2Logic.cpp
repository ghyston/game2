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
#include "Systems/EnergyBalanceSystem.h"
#include "Systems/AISystem.h"

#include "EntityFabric.h"


void Game2Logic::start()
{
	add_system(new RenderSystem());
	add_system(new MoveSystem());
	//add_system(new CollisionSystem());
	add_system(new TargetEnergySystem());
	add_system(new EnergyBalanceSystem());
	add_system(new EnergyGeneratorSystem());
	add_system(new AISystem());
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
	if(node_com->parent.IsSet())
	{
		GetCmpt(PlayerIdComponent, parent_plr_id_cmpt, node_com->parent.Get());
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
			//@todo: add sugar for this (arrays of RefEntity init)!
			RefEntity new_tower;
			gen_com->towers.push_back(new_tower);
			RefEntity * ref = &gen_com->towers.back();
			ref->SetPointer(tower);
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
	std::vector<RefEntity>::iterator it = engen_cmpt->towers.begin();
	Entity * closest_tower = it->Get();
	while (it != engen_cmpt->towers.end())
	{
		GetCmpt(PositionComponent, tower_pos_com, (it->Get()));
			
		Vec2f dist = energy_pos_cmpt->position - tower_pos_com->position;
			
		if(dist.length() < min_dist)
		{
			closest_tower = it->Get();
			min_dist = dist.length();
		}
		it++;
	}
	
	tar_cmpt->target.SetPointer(closest_tower);
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
			targ_cmpt->target.SetPointer(to);
			targ_cmpt->target_enemy = true;
			add_entity(energy);
		}
	}
}

void Game2Logic::remove_tower(Entity * tower)
{
	GetCmpt(NodeComponent, node_com, tower);
	
	//remove from parents' children.
	if(node_com->parent.IsSet())
	{
		GetCmpt(NodeComponent, parent_node_cmpt, node_com->parent.Get());
		std::vector<RefEntity>::iterator it = parent_node_cmpt->children.begin();
		while (it != parent_node_cmpt->children.end())
		{
			if(it->Get() == tower)
			{
				it->UnsetPointer(); //?
				parent_node_cmpt->children.erase(it);
				break;
			}
			else
			{
				it++;
			}
		}
	}
	
	//Remove parent's from children
	std::vector<RefEntity>::iterator it = node_com->children.begin();
	while (it != node_com->children.end())
	{
		GetCmpt(NodeComponent, child_node_comp, it->Get());
		child_node_comp->parent.UnsetPointer();
		it->UnsetPointer();
		it++;
	}
	node_com->children.clear();
	
	//Remove self
	tower->mark_deleted();
}








