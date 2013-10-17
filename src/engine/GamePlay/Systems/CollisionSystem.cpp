#include "CollisionSystem.h"
#include "../../GameEngine.h"
#include "../EntityFabric.h"

void CollisionSystem::update(Entity* entity)
{
	position_com = (PositionComponent*)entity->get_component(ComponentsType::POSITION_COMPONENT);
	move_com = (MovementComponent*)entity->get_component(ComponentsType::MOVEMENT_COMPONENT);
	
	if(entity->has_component(ComponentsType::TARGET_COMPONENT))
	{
		TargetComponent * target_com = (TargetComponent *)
			entity->get_component(ComponentsType::TARGET_COMPONENT);
		
		if(target_com->target == NULL)
			return;
		
		PositionComponent * target_pos = (PositionComponent*)target_com->target->get_component(ComponentsType::POSITION_COMPONENT);
		
		Vec2f dist = Vec2f(target_pos->position.x - position_com->position.x,
						   target_pos->position.y - position_com->position.y);
		
		if(dist.x < 0.1f && dist.y < 0.1f)
			entity->clear();
		
	}
	
	/// ---------JFT------------------------
	
	/*Vec2f borders(-1.0f, 1.0f);
	
	if(	position_com->position.x < borders.x || 
		position_com->position.x > borders.y || 
		position_com->position.y < borders.x || 
		position_com->position.y > borders.y)
	{
		move_com->speed = Vec2f(0.0f, 0.0f);
		
		if(position_com->position.x < borders.x)
		{
			position_com->position.x = borders.x;
			move_com->velocity.x = move_com->velocity.x * -1.0f;
		}
		
		if(position_com->position.x > borders.y)
		{
			position_com->position.x = borders.y;
			move_com->velocity.x = move_com->velocity.x * -1.0f;
		}
		
		if(position_com->position.y < borders.x)
		{
			position_com->position.y = borders.x;
			move_com->velocity.y = move_com->velocity.y * -1.0f;
		}
		
		if(position_com->position.y > borders.y)
		{
			position_com->position.y = borders.y;
			move_com->velocity.y = move_com->velocity.y * -1.0f;
		}
		
		GameEngine::get_data()->logic.add_entity(EntityFabric::get_tower(Vec2f(0.0f, 0.0f)));
	}*/
	/// ---------JFT------------------------
}
