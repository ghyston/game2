#include "CollisionSystem.h"
#include "../../GameEngine.h"
#include "../EntityFabric.h"
#include <cmath>
#include <cstdlib>

void CollisionSystem::update(Entity* entity)
{
	if(!HasCmpt(PositionComponent, entity) ||
	   !HasCmpt(MovementComponent, entity) ||
	   !HasCmpt(TargetComponent, entity))
		return;
	
	GetCmpt(PositionComponent,	position_com,	entity);
	GetCmpt(TargetComponent,		target_com,		entity);
	
	if(!target_com->target.IsSet())
		return;
	
	if(!HasCmpt(PositionComponent, target_com->target.Get()))
		return;
	
	GetCmpt(PositionComponent, target_pos, target_com->target.Get());
		
	Vec2f dist = target_pos->position - position_com->position;
	dist.x = fabs(dist.x);
	dist.y = fabs(dist.y);
		
	if((dist.x < 0.1f) && (dist.y < 0.1f))
	{
		entity->mark_deleted();
		
		Vec2f coords;
		// @todo: remove this magic magic magic magic!
		coords.x = 0.5f * ((rand() % 100) * 0.02f - 1.0f);
		coords.y = 0.5f * ((rand() % 100) * 0.02f - 1.0f);
		
		Entity* new_energy = EntityFabric::create_energy(coords);
		GetCmpt(MovementComponent, move_com, new_energy);
			
		Vec2f new_speed(0.0f, 0.0f);
		move_com->speed = new_speed;
		GameEngine::global_data->logic.add_entity(new_energy);
		
		//@todo: add has_component!
		if(!HasCmpt(EnergyStorageComponent, target_com->target.Get()))
			return;
		
		GetCmpt(EnergyStorageComponent, enesto, target_com->target.Get());
		if(!enesto->is_full())
			enesto->value++;
	}
	
}
