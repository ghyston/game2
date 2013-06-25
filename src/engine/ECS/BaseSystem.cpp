#include "BaseSystem.h"
#include "Entity.h"

bool BaseSystem::check_components(Entity * entity)
{
	IComponent* component;
	for(size_t i = 0; i < components_types.size(); i++)
	{
		component = entity->get_component(components_types[i]);
		if(component == NULL)
			return false;
	}
	return true;
}
	
void BaseSystem::process(Entity * entity)
{
	if(check_components(entity))
		update(entity);
}
