//
//  TargetEnergySystem.cpp
//  Game2
//
//  Created by Stepanov Ilia on 10/17/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "TargetEnergySystem.h"
#include "../../GameEngine.h"
#include "../../ECS/GameLogic.h"

//@todo: убрать\прокомментить этот феерический высер
// @todo: и сделать это, видимо, перед релизом
void TargetEnergySystem::update(EntityPtr entity)
{
	if(!HasCmpt(TargetComponent, entity))
		return;
		
	GetCmpt(TargetComponent, target_com, entity);
	
	//If target is null, dissappear
	if(!target_com->target.is_set())
	{
		entity->mark_deleted();
		return;
	}
		
	EntityPtr target = target_com->target;
	GetCmpt(EnergyStorageComponent, enesto, target);
	GetCmpt(PositionComponent, target_pos_com, target);
	GetCmpt(NodeComponent, target_node_com, target);
		
	GetCmpt(MovementComponent, move_com, entity);
	GetCmpt(PositionComponent, pos_com, entity);

	//If energy reached target
	Vec2f dist = target_pos_com->position - pos_com->position;
	bool target_changed = false;
	if(dist.length() < 0.01f)
	{
		//Check, is target enemy tower
		if(target_com->target_enemy)
		{
			GetCmpt(EnergyStorageComponent, target_enesto_cmpt, target_com->target);
			
			target_enesto_cmpt->rem_energy(5);
			entity->mark_deleted();
			return;
		}
		
		pos_com->position = target_pos_com->position;
		
		EntityIt it = target_node_com->children.begin();
		
		EntityPtr next_target = target;
		
		float min_energy_balance = 1.0f;
		while (it != target_node_com->children.end())
		{
			GetCmpt(EnergyStorageComponent, enesto_child, (it->get()));
			if(enesto_child->balance < min_energy_balance)
			{
				next_target = (*it);
				min_energy_balance = enesto_child->balance;
			}
			it++;
		}
			
		if(min_energy_balance == 1.0) //children are full (or not exist)
		{
			if(!enesto->is_full())
				merge_energy(target, entity);
			else
			{
				// All childs are full and we have reached base tower.
				if(!target_node_com->parent.is_set())
				{
					entity->mark_deleted();
					return;
				}
				
				target_com->target = target_node_com->parent;

				target_changed = true;
			}
		}
		else
		{
			target_com->target = next_target;
			target_changed = true;
		}

	}
	
	if(target_changed)
	{
		GetCmpt(PositionComponent, new_target_pos, target_com->target);
		dist = new_target_pos->position - pos_com->position;
	}
			
	move_com->speed = dist;
	move_com->speed.length(0.5f); //0.5 per sec.

}

void TargetEnergySystem::merge_energy(EntityPtr tower, EntityPtr energy)
{
	GetCmpt(EnergyStorageComponent, enesto, tower);
	enesto->add_energy(1); // @todo: this should be out constant!
	energy->mark_deleted();
}
