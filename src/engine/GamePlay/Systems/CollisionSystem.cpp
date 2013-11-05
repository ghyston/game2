#include "CollisionSystem.h"
#include "../../GameEngine.h"
#include "../EntityFabric.h"
#include <cmath>
#include <cstdlib>

void CollisionSystem::update(Entity* entity)
{
	if(!entity->has_component<PositionComponent>() ||
	   !entity->has_component<MovementComponent>() ||
	   !entity->has_component<TargetComponent>())
		return;
	
	position_com = entity->get_component<PositionComponent>();
	move_com = entity->get_component<MovementComponent>();
	target_com = entity->get_component<TargetComponent>();
	
	if(target_com->target.pointer == NULL)
		return;
	
	if(!target_com->target.pointer->has_component<PositionComponent>())
		return;
		
	PositionComponent * target_pos;
	target_pos = target_com->target.pointer->get_component<PositionComponent>();
		
	Vec2f dist;
	dist.x = fabs(target_pos->position.x - position_com->position.x);
	dist.y = fabs(target_pos->position.y - position_com->position.y);
		
	if((dist.x < 0.1f) && (dist.y < 0.1f))
	{
		entity->mark_deleted();
		
		Vec2f coords;
		// @todo: remove this magic magic magic magic!
		coords.x = 0.5f * ((rand() % 100) * 0.02f - 1.0f);
		coords.y = 0.5f * ((rand() % 100) * 0.02f - 1.0f);
		
		Entity* new_energy = EntityFabric::create_energy(coords);
		MovementComponent* move_com;
		move_com = new_energy->get_component<MovementComponent>();
			
		Vec2f new_speed(0.0f, 0.0f);
		move_com->speed = new_speed;
		GameEngine::global_data->logic.add_entity(new_energy);
		
		//@todo: add has_component!
		EnergyStorageComponent * enesto =
			target_com->target.pointer->get_component<EnergyStorageComponent>();
		if(!enesto->is_full())
			enesto->value++;
	}
	
}
