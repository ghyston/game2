//
//  TargetEnergySystem.cpp
//  Game2
//
//  Created by Stepanov Ilia on 10/17/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "TargetEnergySystem.h"
#include "../../GameEngine.h"

//@todo: убрать\прокомментить этот феерический высер
void TargetEnergySystem::update(Entity * entity)
{
	if(!entity->has_component(ComponentsType::TARGET_COMPONENT))
		return;
		
	target_com = (TargetComponent *)entity->get_component(ComponentsType::TARGET_COMPONENT);
	
	if(target_com->target == NULL)
	{
		//@todo: find closest tower in radius
		std::vector<Entity*>& entities =
			GameEngine::global_data->logic.entities;
		
		//@todo: too ugly
		PositionComponent * pos_com = (PositionComponent *)
			entity->get_component(ComponentsType::POSITION_COMPONENT);
		
		float min_dist = 10000.0f;
		Entity* closest_target = NULL;
		
		for(size_t i = 0; i < entities.size(); i++)
		{
			Entity * temp = entities[i];
			if(
			   !temp->has_component(ComponentsType::POSITION_COMPONENT)
			   || temp == entity)
				continue;
			
			PositionComponent * target_pos = (PositionComponent *)temp->get_component(ComponentsType::POSITION_COMPONENT);
			
			// @todo: wtf?! Why it doesn't work anymore?
			Vec2f dist = Vec2f(
				target_pos->position.x - pos_com->position.x,
				target_pos->position.y - pos_com->position.y);
			
			if((dist.x + dist.y) < min_dist)
			{
				closest_target = temp;
				min_dist = dist.x + dist.y;
			}
		}
		
		if(closest_target != NULL)
			target_com->target = closest_target;
	}
	else
	{
		MovementComponent * move_com = (MovementComponent *)entity->get_component(ComponentsType::MOVEMENT_COMPONENT);
		
		PositionComponent * pos_com = (PositionComponent *)target_com->target->get_component(ComponentsType::POSITION_COMPONENT);
		
		Vec2f target_pos = pos_com->position;
		
		pos_com = (PositionComponent *)entity->get_component(
			ComponentsType::POSITION_COMPONENT);
		
		Vec2f velocity = Vec2f(
			- pos_com->position.x + target_pos.x,
			- pos_com->position.y + target_pos.y);
		
		//@todo: too ugly here
		move_com->velocity = velocity;
	}
}