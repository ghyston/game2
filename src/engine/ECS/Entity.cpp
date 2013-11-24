#include "Entity.h"

size_t Entity::first_unused_id = 0;

Entity * Entity::create()
{
	Entity * entity = new Entity();
	entity->set_id(Entity::first_unused_id++);
	return entity;
}

Entity::Entity()
{
	deleted_mark = false;
	clear();
}

void Entity::clear()
{
	for(std::map<size_t, IComponent*>::iterator it = components.begin();
		it != components.end(); it++)
	{
		delete it->second;
	}
	components.clear();
}

void Listnerable::mark_deleted()
{
	deleted_mark = true;
	
	std::vector<RefEntity*>::iterator it = waitors.begin();
	while (it != waitors.end())
	{
		(*it)->DelRef();
		it++;
	}
}

void Listnerable::register_listener(RefEntity * ref)
{
	waitors.push_back(ref);
}

void Listnerable::unregister_listener(RefEntity * ref)
{
	// @todo: only one listener?
	std::vector<RefEntity*>::iterator it =
	std::find(waitors.begin(), waitors.end(), ref);
	if(it != waitors.end())
		waitors.erase(it);
}
