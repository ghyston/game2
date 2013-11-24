//
//  AISystem.cpp
//  Game2
//
//  Created by Stepanov Ilia on 24/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "AISystem.h"

void AISystem::update(Entity * entity)
{
	if(!HasCmpt(PlayerIdComponent, entity))
		return;
	
	GetCmpt(PlayerIdComponent, plr_id_cmp, entity);
	if(plr_id_cmp->player_id == GlobalData::PLAYER_ID_1)
		return;
	
	//for towers only
	if(!HasCmpt(EnergyStorageComponent, entity))
		return;
	
	// Not enouth energy
	GetCmpt(EnergyStorageComponent, enesto_cmpt, entity);
	if(enesto_cmpt->value < 75)
		return;
	
	GetCmpt(PositionComponent, pos_com, entity)
	
	float rad = (rand() % 100) * 0.5 / 100.0f + 0.15f;
	float angle = (rand() % 200) / 100.0f;
	Vec2f coords (rad * __cospi(angle), rad * __sinpi(angle));
	
	Vec2f new_coords = pos_com->position + coords;
	
	enesto_cmpt->rem_energy(70);
	Entity * new_tower =
		EntityFabric::get_tower(entity, new_coords);
	GameEngine::get_data()->logic.add_tower(new_tower);

	
}