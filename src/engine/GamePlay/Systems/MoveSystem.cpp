#include "MoveSystem.h"

void MoveSystem::update(Entity* entity)
{
    if(
       !entity->has_component<PositionComponent>() ||
       !entity->has_component<MovementComponent>())
        return;
    
	position_com = entity->get_component<PositionComponent>();
	move_com = entity->get_component<MovementComponent>();
	
	float delta = Timer::get_delta();
	
	position_com->position.x += move_com->speed.x * delta;
	position_com->position.y += move_com->speed.y * delta;
	move_com->speed.x += move_com->velocity.x * delta;
	move_com->speed.y += move_com->velocity.y * delta;
}