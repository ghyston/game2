#include "MoveSystem.h"

void MoveSystem::update(Entity* entity)
{
    if(
       !entity->has_component(ComponentsType::POSITION_COMPONENT) ||
       !entity->has_component(ComponentsType::MOVEMENT_COMPONENT))
        return;
    
    
	position_com = (PositionComponent*)entity->get_component(ComponentsType::POSITION_COMPONENT);
	move_com = (MovementComponent*)entity->get_component(ComponentsType::MOVEMENT_COMPONENT);
	
	float delta = Timer::get_delta();
	
	position_com->position.x += move_com->speed.x * delta;
	position_com->position.y += move_com->speed.y * delta;
	move_com->speed.x += move_com->velocity.x * delta;
	move_com->speed.y += move_com->velocity.y * delta;
}