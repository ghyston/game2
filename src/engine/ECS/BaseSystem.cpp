#include "BaseSystem.h"
#include "Entity.h"

void BaseSystem::process(Entity * entity)
{
	if(entity == NULL)
		return;
	update(entity);
}
