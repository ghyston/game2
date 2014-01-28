#include "BaseSystem.h"
#include "Entity.h"

void BaseSystem::process(EntityPtr entity)
{
	if(entity->is_deleted())
		return;
	update(entity);
}
