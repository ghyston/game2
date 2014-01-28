#include "Entity.h"

Entity * Entity::create()
{
	Entity * entity = new Entity();
	return entity;
}

Entity::Entity()
{
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
