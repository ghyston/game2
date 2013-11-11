//
//  EnergyBalanceSystem.cpp
//  Game2
//
//  Created by Stepanov Ilia on 05/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "EnergyBalanceSystem.h"
#include "EntityFabric.h"
#include "../../GameEngine.h"
int EnergyBalanceSystem::average_energy = 0;

void EnergyBalanceSystem::update(Entity * entity)
{
	if(!HasCmpt(EnergyStorageComponent, entity))
		return;
	
	GetCmpt(EnergyStorageComponent, enesto, entity);
	count_storage++;
	sum_energy += enesto->value;
}

void EnergyBalanceSystem::pre_step()
{
	EnergyBalanceSystem::average_energy = 0;
	sum_energy = 0;
	count_storage = 0;
/*	if((rand() % 100) < 10)
	{
		Vec2f coords;
		// @todo: this should goes to energy_creator entity
		coords.x = 0.5f * ((rand() % 100) * 0.02f - 1.0f);
		coords.y = 0.5f * ((rand() % 100) * 0.02f - 1.0f);
	
		Entity* new_energy = EntityFabric::create_energy(coords);
		GameEngine::global_data->logic.add_entity(new_energy);
	}*/

}

void EnergyBalanceSystem::post_step()
{
	EnergyBalanceSystem::average_energy = sum_energy / count_storage;
}