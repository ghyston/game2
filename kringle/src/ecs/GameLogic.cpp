#include "GameLogic.h"
#include "../Common/VecShrPtr.h"


void GameLogic::step()
{
	std::vector<BaseSystem*>::iterator systemIt = systems.begin();
	for(; systemIt != systems.end(); systemIt++)
	{
		BaseSystem* system = (*systemIt);
		system->pre_step();
		
		// First, process all positioned entities
		for(int iX = -map.entity_map.getWidth();
			iX < map.entity_map.getWidth(); iX++)
		{
			for(int iY = -map.entity_map.getHeight();
				iY < map.entity_map.getHeight(); iY++)
			{
				Entities& entList = map.entity_map.getEntitiesFromCell(iX, iY);
				
				for(EntityIt it = entList.begin();	it != entList.end(); it++)
					system->process(*it);
			}
		}
		
		// Second, process all unpositioned entities
		for(EntityIt it = entities.begin();	it != entities.end(); it++)
			system->process(*it);
		
		system->post_step();
		
		// Remove all entities, that was deleted.
		map.entity_map.checkFroRemovedEntities();
		RemoveDeletedObjectsFromContainer(entities);
	}
}

void GameLogic::add_system(BaseSystem * system)
{
	systems.push_back(system);
}

void GameLogic::add_entity(EntityPtr entity)
{
	//@todo: there souldn't be any component names on Common!
	if(HasCmpt(PositionComponent, entity.lock()))
	{
		GetCmpt(PositionComponent, pos_com, entity.lock());
		map.entity_map.addEntity(pos_com->position.x, pos_com->position.y, entity);
	}
	else
		entities.push_back(entity);
}

void GameLogic::LoadMap(int width, int height)
{
	map.map_width = width;
	map.map_height = height;
	
	map.InitGrids();
}

Entities& GameLogic::get_entities_by_coords(Vec2f& pos)
{
	return map.get_entities_by_coords(pos);
}


