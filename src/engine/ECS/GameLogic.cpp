#include "GameLogic.h"

void GameLogic::start()
{
	//render_system = new RenderSystem();
}
	
void GameLogic::step()
{
	// @todo: remove deleted components here!
	
	for(size_t i = 0; i < systems.size(); i++)
	{
		// @todo: add init_system
		for(std::map<size_t, Entity*>::iterator it = entities.begin();
			it != entities.end(); it++)

		{
			if(!it->second->is_deleted())
				systems[i]->process(it->second);
		}
		erase_removed_entities();
	}
}
	
void GameLogic::stop()
{
	;
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