#include "GameLogic.h"
#include "../Common/VecShrPtr.h"


void GameLogic::step()
{	
	for(size_t i = 0; i < systems.size(); i++)
	{
		systems[i]->pre_step();
		
		// First, process all positioned entities
		for(int iX = -map.entity_map.getWidth();
			iX < map.entity_map.getWidth(); iX++)
		{
			for(int iY = -map.entity_map.getHeight();
				iY < map.entity_map.getHeight(); iY++)
			{
				//@todo: remove this complex list, this is 4 debug!
				Entities& entList = map.entity_map.getEntitiesFromCell(iX, iY);
				
				for(EntityIt it = entList.begin();	it != entList.end(); it++)
					systems[i]->process(*it);
			}
		}
		
		for(EntityIt it = entities.begin();	it != entities.end(); it++)
			systems[i]->process(*it);
		systems[i]->post_step();
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
	if(HasCmpt(PositionComponent, entity))
	{
		GetCmpt(PositionComponent, pos_com, entity);
		map.entity_map.addEntity(pos_com->position.x, pos_com->position.y, entity);
	}
	else
		entities.push_back(entity);
}

void GameLogic::LoadMap(int width, int height, float cell_size)
{
	static const int grids_ratio = 5;
	
	map.entity_map.InitMap(width, height, cell_size);
	map.pass_map.InitMap(width * grids_ratio, height * grids_ratio, cell_size / grids_ratio);
}

Entities& GameLogic::get_entities_by_coords(Vec2f& pos)
{
	return map.get_entities_by_coords(pos);
}


