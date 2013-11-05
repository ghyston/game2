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
	if(!entity->has_component<TargetComponent>())
		return;
		
	target_com = entity->get_component<TargetComponent>();
	
	if(target_com->target.pointer == NULL)
	{
		//@todo: find closest tower in radius
		Entities& entities = GameEngine::global_data->logic.get_entities();
		
		//@todo: too ugly
		PositionComponent * pos_com = entity->get_component<PositionComponent>();
		
		float min_dist = 10000.0f;
		Entity* closest_target = NULL;
		
		for(EntityIt it = entities.begin();	it != entities.end(); it++)
		{
			Entity * temp = it->second;
			//if(temp->type != Entity::Types::TOWER)
			//	continue;
			
			if(!temp->has_component<EnergyStorageComponent>() || temp == entity)
				continue;
			
			es_com = temp->get_component<EnergyStorageComponent>();
			if(es_com->is_full())
				continue;
			
			PositionComponent * target_pos;
			target_pos = temp->get_component<PositionComponent>();
			
			// @todo: wtf?! Why it doesn't work anymore?
			Vec2f dist = Vec2f(
				fabs(target_pos->position.x - pos_com->position.x),
				fabs(target_pos->position.y - pos_com->position.y));
			
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
			MovementComponent * move_com = entity->
				get_component<MovementComponent>();
			
			move_com->velocity = move_com->speed * -0.1f;
			//move_com->velocity.x = move_com->speed.x * -0.1f;
			//move_com->velocity.y = move_com->speed.y * -0.1f;
		}
	}
	else
	{
		EnergyStorageComponent * enesto = target_com->target.pointer->get_component<EnergyStorageComponent>();
		if(enesto->is_full())
		{
			//@todo: check, is del_ref work correctly!
			target_com->target.del_ref();
			return;
		}
		
		
		MovementComponent * move_com = entity->get_component<MovementComponent>();
		
		PositionComponent * pos_com;
		pos_com = target_com->target.pointer->get_component<PositionComponent>();
		
		Vec2f target_pos = pos_com->position;
		
		pos_com = entity->get_component<PositionComponent>();
		
		Vec2f velocity = Vec2f(
			(- pos_com->position.x + target_pos.x),
			(- pos_com->position.y + target_pos.y));
				
		//@todo: too ugly here
		move_com->velocity = velocity;
	}
}