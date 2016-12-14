#include "MoveSystem.h"

void MoveSystem::pre_step()
{
	moved_entities.clear();
}

void MoveSystem::update(EntityPtr entity)
{
    if(
       !HasCmpt(PositionComponent, entity.lock()) ||
       !HasCmpt(MovementComponent, entity.lock()))
        return;
    
	GetCmpt(PositionComponent, pos_com, entity.lock());
	GetCmpt(MovementComponent, move_com, entity.lock());
	
	float delta = Timer::get_delta();
	
	if(move_com->speed.x != 0.0f || move_com->speed.y != 0.0f)
		moved_entities.push_back(entity);
		
	pos_com->old_position = pos_com->position;
	pos_com->position += move_com->speed * delta;

	move_com->speed += move_com->velocity * delta;
}

void MoveSystem::post_step()
{
//	RemoveDeletedObjectsFromContainer(moved_entities);
	
	for(EntityIt it = moved_entities.begin(); it != moved_entities.end(); it++)
	{
		GetCmpt(PositionComponent, pos_com, (it->lock()));
		GameEngine::get_data()->logic.getMap()->RepositionEntityToCorrectCell
			(*it, pos_com->old_position, pos_com->position);
	}
}
