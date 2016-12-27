//
//  EnergyCreatorSystem.cpp
//  Game2
//
//  Created by Stepanov Ilia on 11/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//
#include <math.h>

#include "common/VecShrPtr.h"
#include "core/Systems/EnergyCreatorSystem.h"
#include "core/GameEngine.h"
#include "core/Game2Logic.h"
#include "core/EntityFabric.h"

void EnergyGeneratorSystem::update(EntityPtr entity)
{
	if(!HasCmpt(EnergyGeneratorComponent, entity.lock()))
		return;
	
	GetCmpt(EnergyGeneratorComponent, en_gen_cmpt, entity.lock());
	GetCmpt(PositionComponent, pos_cmpt, entity.lock());
	
	RemoveDeletedObjectsFromContainer(en_gen_cmpt->towers);
	if(en_gen_cmpt->towers.size() == 0)
		return;
	
	if((rand() % 100) < (en_gen_cmpt->intensivity * 100))
	{
		float rad = (rand() % 100) * en_gen_cmpt->radius / 100.0f;
		float angle = (rand() % 200) / 100.0f;
		Vec2f coords (rad * cos(angle * M_PI), rad * sin(angle * M_PI));
		
		coords += pos_cmpt->position;
		
		GameEngine::global_data->logic.add_energy(
			EntityFabric::create_energy(coords), entity);
	}
	
}
