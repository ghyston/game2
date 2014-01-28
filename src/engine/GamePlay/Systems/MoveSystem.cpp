#include "MoveSystem.h"

void MoveSystem::update(EntityPtr entity)
{
    if(
       !HasCmpt(PositionComponent, entity) ||
       !HasCmpt(MovementComponent, entity))
        return;
    
	GetCmpt(PositionComponent, pos_com, entity);
	GetCmpt(MovementComponent, move_com, entity);
	
	float delta = Timer::get_delta();
	
	pos_com->position += move_com->speed * delta;
	move_com->speed += move_com->velocity * delta;
}