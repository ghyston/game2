//
//  EnergyBalanceSystem.cpp
//  Game2
//
//  Created by Stepanov Ilia on 05/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "EnergyBalanceSystem.h"
#include "../../GameEngine.h"
#include "../../Timer.h"

int EnergyBalanceSystem::average_energy = 0;

void EnergyBalanceSystem::update(EntityPtr entity)
{
	if(!HasCmpt(EnergyStorageComponent, entity))
		return;
	
	//@todo: this statistics is useless. Delete it
	GetCmpt(EnergyStorageComponent, enesto, entity);
	count_storage++;
	sum_energy += enesto->value;
	
	//Delete tower, if it has zero energy
	if(enesto->is_empty())
		GameEngine::get_data()->logic.remove_tower(entity);
}

void EnergyBalanceSystem::pre_step()
{
	EnergyBalanceSystem::average_energy = 0;
	sum_energy = 0;
	count_storage = 0;
	
	// Main work is here, calculate balance by tree.	
	EntityPtr base_1 = GameEngine::global_data->base_tower_player_1;
	EntityPtr base_2 = GameEngine::global_data->base_tower_player_2;
	
	if(base_1.is_set())	process_base_tower(base_1);
	if(base_2.is_set())	process_base_tower(base_2);
}

void EnergyBalanceSystem::process_base_tower(EntityPtr base)
{
	calc_energy(base);
	
	//Sometimes we need to feed base towers.
	GetCmpt(EnergyStorageComponent, enesto_cmpt, base);
	
	last_time_feeded += Timer::get_delta();
	if(last_time_feeded > 2.0) //Every 2 seconds add 10 energy to base towers
	{
		enesto_cmpt->add_energy(10);
		last_time_feeded = 0.0f;
	}
}

float EnergyBalanceSystem::calc_energy(EntityPtr tower)
{
	if(!tower.is_set() ||
	   !HasCmpt(EnergyStorageComponent, tower) ||
	   !HasCmpt(NodeComponent, tower))
		return 0.0f;
	
	GetCmpt(EnergyStorageComponent, enesto, tower);
	GetCmpt(NodeComponent, node_com, tower);
	
	float result = enesto->get_percentage();
	
	int child_count = 0;
	float childs_energy = 0.0f;
	EntityIt it = node_com->children.begin();
	while (it != node_com->children.end())
	{
		childs_energy += calc_energy(*it);
		child_count++;
		it++;
	}

	if(child_count > 0)
	{
		result /= 2.0f;
		result += childs_energy / (child_count * 2.0f);
	}
	enesto->balance = result;
	return result;
}

void EnergyBalanceSystem::post_step()
{
	EnergyBalanceSystem::average_energy = sum_energy / count_storage;
}