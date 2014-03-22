#include "GameLogic.h"
#include "../Common/VecShrPtr.h"

void GameLogic::step()
{	
	for(size_t i = 0; i < systems.size(); i++)
	{
		systems[i]->pre_step();
		
		// First, process all positioned entities
		for(int iX = 0; iX < map.getWidth(); iX++)
		{
			for(int iY = 0; iY < map.getHeight(); iY++)
			{
				Entities& entList = map.getEntitiesFromCell(iX, iY);
				for(EntityIt it = entList.begin();	it != entList.end(); it++)
					systems[i]->process(*it);
			}
		}
		
		
		for(EntityIt it = entities.begin();	it != entities.end(); it++)
			systems[i]->process(*it);
		systems[i]->post_step();
		map.checkFroRemovedEntities();
		RemoveDeletedObjectsFromContainer(entities);
	}
}

void GameLogic::add_system(BaseSystem * system)
{
	systems.push_back(system);
}

void GameLogic::add_entity(EntityPtr entity)
{
	if(HasCmpt(PositionComponent, entity))
	{
		GetCmpt(PositionComponent, pos_com, entity);
		map.addEntity(pos_com->position.x, pos_com->position.y, entity);
	}
	else
		entities.push_back(entity);
}

Entities& GameLogic::get_entities_by_coords(Vec2f& pos)
{
	return map.getEntitiesFromCell(pos.x, pos.y);
}

bool GameLogic::GetCellPosibility(Vec2i coords)
{
	return map.isCellPass(coords);
}