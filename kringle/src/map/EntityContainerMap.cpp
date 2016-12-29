//
//  EntityContainerMap.cpp
//  Game2
//
//  Created by Stepanov Ilia on 17/05/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#include "EntityContainerMap.h"

void EntityContainerMap::addEntity(float pos_x, float pos_y, EntityPtr entity)
{
	Vec2i coordIndx = getIndexesByCoords(pos_x, pos_y);
	cells[coordIndx.x][coordIndx.y].entities.push_back(entity);
}

void EntityContainerMap::removeEntityFromCell(float pos_x, float pos_y, EntityPtr entity)
{
	Vec2i coordIndx = getIndexesByCoords(pos_x, pos_y);
	// @todo: define foreach entities!
	Entities& entities = cells[coordIndx.x][coordIndx.y].entities;
	
	for(EntityIt it = entities.begin();	it != entities.end(); it++)
	{
		if(it->lock().get() != entity.lock().get())
			continue;
		
		entities.erase(it);
		break;
	}
}

void EntityContainerMap::checkFroRemovedEntities()
{
	std::map<int, std::map<int, MapCell> >::iterator itX = cells.begin();
	for(; itX != cells.end(); itX++)
	{
		std::map<int, MapCell>::iterator itY = itX->second.begin();
		for(; itY != itX->second.end(); itY++)
		{
			RemoveDeletedObjectsFromContainer(itY->second.entities);
		}
		
	}
}

Entities& EntityContainerMap::getEntitiesFromCell(float x, float y)
{
	Vec2i cell_coords = getIndexesByCoords(x, y);
	return getEntitiesFromCell(cell_coords.x, cell_coords.y);
}

Entities& EntityContainerMap::getEntitiesFromCell(int x, int y)
{
	return cells[x][y].entities;
}

