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
void TargetEnergySystem::update(Entity * entity)
{
	if(!HasCmpt(TargetComponent, entity))
		return;
		
	GetCmpt(TargetComponent, target_com, entity);
	
	//If target is null, dissappear
	if(!target_com->target.IsSet())
	{
		del_energy(entity);
		return;
	}
		
	Entity * target = target_com->target.Get();
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
		//@todo: Check, is target enemy tower
		if(target_com->target_enemy)
		{
			GetCmpt(EnergyStorageComponent, target_enesto_cmpt, target_com->target.Get());
			
			target_enesto_cmpt->rem_energy(5);
			del_energy(entity);
			return;
		}
		
		pos_com->position = target_pos_com->position;
		
		std::vector<RefEntity>::iterator it = target_node_com->children.begin();
		
		Entity * next_target = target;
		
		float min_energy_balance = 1.0f;
		while (it != target_node_com->children.end())
		{
			GetCmpt(EnergyStorageComponent, enesto_child, (it->Get()));
			if(enesto_child->balance < min_energy_balance)
			{
				next_target = it->Get();
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
				if(!target_node_com->parent.IsSet())
				{
					del_energy(entity);
					return;
				}
				
				target_com->target.UnsetPointer();
				target_com->target.SetPointer(target_node_com->parent.Get());

				target_changed = true;
			}
		}
		else
		{
			target_com->target.SetPointer(next_target);
			target_changed = true;
		}

	}
	
	if(target_changed)
	{
		GetCmpt(PositionComponent, new_target_pos, target_com->target.Get());
		dist = new_target_pos->position - pos_com->position;
	}
			
	move_com->speed = dist;
	move_com->speed.lenth(0.5f); //0.5 per sec.

}

void TargetEnergySystem::merge_energy(Entity * tower, Entity * energy)
{
	GetCmpt(EnergyStorageComponent, enesto, tower);
	enesto->add_energy(1); // @todo: this should be out constant!
	del_energy(energy);
}

void TargetEnergySystem::del_energy(Entity * energy)
{
	GetCmpt(TargetComponent, target_com, energy);
	target_com->target.UnsetPointer();
	energy->mark_deleted();
}