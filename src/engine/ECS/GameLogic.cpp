#include "GameLogic.h"

void GameLogic::step()
{	
	for(size_t i = 0; i < systems.size(); i++)
	{
		systems[i]->pre_step();
		for(EntityIt it = entities.begin();	it != entities.end(); it++)
			systems[i]->process(it->second);
		systems[i]->post_step();
		erase_removed_entities();
	}
}

void GameLogic::add_system(BaseSystem * system)
{
	systems.push_back(system);
}

void GameLogic::add_entity(Entity * entity)
{
	entities[entity->get_id()] = entity;
}

void GameLogic::remove_entity(Entity * entity)
{
	entity->mark_deleted();
}

void GameLogic::remove_entity(size_t entity_id)
{
	std::map<size_t, Entity*>::iterator it = entities.find(entity_id);
	remove_entity(it->second);
}

void GameLogic::erase_removed_entities()
{
	EntityIt it = entities.begin();
	while (it != entities.end())
	{
		if (it->second->is_deleted())
		{
			it->second->clear();
			delete it->second;
			entities.erase(it++);
		}
		else
			++it;
	}
		
}