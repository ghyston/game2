#include "BaseSystem.h"
#include "Entity.h"

void BaseSystem::process(Entity * entity)
{
	if(entity == NULL || entity->is_deleted())
		return;
	update(entity);
}
