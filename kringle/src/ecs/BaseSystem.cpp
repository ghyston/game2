#include "BaseSystem.h"
#include "Entity.h"

void BaseSystem::process(EntityPtr entity)
{
	if(entity.expired())
		return;
	update(entity);
}
