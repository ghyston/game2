#include "Entity.h"

EntityPtr Entity::create()
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entity->_self = entity;
	
	//Entity * entity = new Entity();
	//entity->_self = make_ entity;
	return entity;
}

Entity::Entity()
{
	clear();
}

Entity::~Entity()
{
	printf("Entity d-tor");
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

void Entity::mark_deleted()
{
	_self = nullptr;
}
