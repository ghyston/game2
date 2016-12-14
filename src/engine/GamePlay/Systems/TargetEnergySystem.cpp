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
void TargetEnergySystem::update(EntityPtr entity)
{
    Entity * pEntity = entity.lock().get();
    
	if(!HasCmpt(TargetComponent, pEntity))
		return;
		
	GetCmpt(TargetComponent, target_com, pEntity);
	
	//If target is null, dissappear
	if(target_com->target.expired())
	{
		pEntity->mark_deleted();
		return;
	}
	
    Entity * pTarget = target_com->target.lock().get();
	GetCmpt(EnergyStorageComponent, enesto, pTarget);
	GetCmpt(PositionComponent, target_pos_com, pTarget);
	GetCmpt(NodeComponent, target_node_com, pTarget);
		
	GetCmpt(MovementComponent, move_com, pEntity);
	GetCmpt(PositionComponent, pos_com, pEntity);

	//If energy reached target
	Vec2f dist = target_pos_com->position - pos_com->position;
	bool target_changed = false;
	if(dist.length() < 0.01f)
	{
		//Check, is target enemy tower
		if(target_com->target_enemy)
		{
			GetCmpt(EnergyStorageComponent, target_enesto_cmpt, pTarget);
			
			target_enesto_cmpt->rem_energy(5);
			pEntity->mark_deleted();
			return;
		}
		
		//@todo: changing entity position thoughtlessly is VERY dangerous!
		// it cost 3 evenings of debug.
		// Reposition here break GameLogic entity iterator
		// Changing position without changing cell can produce entityPtr
		// duplicate on two cells.
		// @todo: changing entity position should be on map or gamelogic.
		
		/*pos_com->old_position = pos_com->position;
		pos_com->position = target_pos_com->position;
		GameEngine::get_data()->logic.getMap()->RepositionEntityToCorrectCell
			(entity, pos_com->old_position, pos_com->position);*/
		
		EntityIt it = target_node_com->children.begin();
		
		EntityPtr next_target = entity;
		
		float min_energy_balance = 1.0f;
		while (it != target_node_com->children.end())
		{
			GetCmpt(EnergyStorageComponent, enesto_child, (it->lock()));
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
				merge_energy(target_com->target, entity);
			else
			{
				// All childs are full and we have reached base tower.
				if(target_node_com->parent.expired())
				{
					pEntity->mark_deleted();
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
		GetCmpt(PositionComponent, new_target_pos, target_com->target.lock());
		dist = new_target_pos->position - pos_com->position;
	}

	// Energy, moving to enemy target, move unlinear
	if (target_com->target_enemy)
	{
		
	}
	else
	{
		move_com->speed = dist;
		move_com->speed.length(0.5f); //0.5 per sec.
	}

}

void TargetEnergySystem::merge_energy(EntityPtr tower, EntityPtr energy)
{
	GetCmpt(EnergyStorageComponent, enesto, tower.lock());
	enesto->add_energy(10); // @todo: this should be out constant!
	energy.lock()->mark_deleted();
}
