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
void TargetEnergySystem::update(Entity * entity)
{
	if(!HasCmpt(TargetComponent, entity))
		return;
		
	GetCmpt(TargetComponent, target_com, entity);
	
	//We doesn't have target now, find.
	if(target_com->target.pointer == NULL)
	{
		//@todo: find closest tower in radius (not by square)
		Entities& entities = GameEngine::global_data->logic.get_entities();
		
		GetCmpt(PositionComponent, pos_com, entity);
		
		float min_dist = 10000.0f; //@todo: remove this dirty hack!
		Entity* closest_target = NULL;
		
		for(EntityIt it = entities.begin();	it != entities.end(); it++)
		{
			Entity * temp = it->second;
			
			if(!HasCmpt(EnergyStorageComponent, temp) || temp == entity)
				continue;
			
			GetCmpt(EnergyStorageComponent, es_com, temp);
			if(es_com->is_full())
				continue;

			GetCmpt(PositionComponent, target_pos, temp);
			
			Vec2f dist = target_pos->position - pos_com->position;
			dist.x = fabs(dist.x);
			dist.y = fabs(dist.y);
			
			if((dist.x + dist.y) < min_dist)
			{
				closest_target = temp;
				min_dist = dist.x + dist.y;
			}
		}
		
		if(closest_target != NULL)
		{
			target_com->target.pointer = closest_target;
			closest_target->register_listener(&target_com->target);
		}
		else
		{
			GetCmpt(MovementComponent, move_com, entity);
			move_com->velocity = move_com->speed * -0.1f;
		}
	}
	else //entity has target
	{
		Entity * target = target_com->target.pointer;
		GetCmpt(EnergyStorageComponent, enesto, target);
		GetCmpt(PositionComponent, target_pos_com, target);
		GetCmpt(NodeComponent, target_node_com, target);
		
		GetCmpt(MovementComponent, move_com, entity);
		GetCmpt(PositionComponent, pos_com, entity);

		Vec2f dist = target_pos_com->position - pos_com->position;
		if(dist.x < 0.01f && dist.y < 0.01f) //@todo: square collision!
		{
			pos_com->position = target_pos_com->position;
			if(target_node_com->parent != NULL)
			{
				GetCmpt(EnergyStorageComponent, parent_es_com, target_node_com->parent);
				if(!parent_es_com->is_full())
				{
					
					target_com->target.pointer = target_node_com->parent;
				}
				else
				{
					merge_energy(target, entity);
				}
			}
			else
				merge_energy(target, entity);
		}
		
		if(enesto->is_full())
		{
			//@todo: check, is del_ref work correctly!
			target_com->target.del_ref();
			return;
		}
		
		
		move_com->speed = dist;
		move_com->speed.lenth(0.5f); //0.5 per sec.
	}
}

void TargetEnergySystem::merge_energy(Entity * tower, Entity * energy)
{
	GetCmpt(EnergyStorageComponent, enesto, tower);
	if(!enesto->is_full())
		enesto->value++;
	GetCmpt(TargetComponent, target_com, energy);
	target_com->target.del_ref();
	energy->mark_deleted();
}