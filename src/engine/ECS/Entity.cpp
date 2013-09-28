#include "Entity.h"

Entity::Entity()
{
	clear();
}

void Entity::add_component(int component_id, IComponent* component)
{
	components[component_id] = component;
}
	
IComponent* Entity::get_component(int component_id)
{
	return components[component_id];
}

bool Entity::has_component(int component_id)
{
	return components[component_id] != NULL;
}

void Entity::clear()
{
	for(int i = ComponentsType::__FIRST; 
		i < ComponentsType::__COUNT; i++)
	{		
		/*if(components[i] == NULL)
			continue;
		
		// @todo: может ёбнуть
		components[i].mark_deleted();*/
		components[i] = NULL;		
	}
}