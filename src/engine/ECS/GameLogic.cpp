#include "GameLogic.h"
#include "../Common/VecShrPtr.h"

void GameLogic::step()
{	
	for(size_t i = 0; i < systems.size(); i++)
	{
		systems[i]->pre_step();
		for(EntityIt it = entities.begin();	it != entities.end(); it++)
			systems[i]->process(*it);
		systems[i]->post_step();
		RemoveDeletedObjectsFromContainer(entities);
	}
}

void GameLogic::add_system(BaseSystem * system)
{
	systems.push_back(system);
}

void GameLogic::add_entity(EntityPtr entity)
{
	entities.push_back(entity);
}

void GameLogic::remove_entity(Entity * entity)
{
	entity->mark_deleted();
}
