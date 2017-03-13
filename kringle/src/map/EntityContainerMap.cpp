//
//  EntityContainerMap.cpp
//  Game2
//
//  Created by Stepanov Ilia on 17/05/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#include "EntityContainerMap.h"

void EntityContainerMap::addEntity(EntityPtr entity)
{
	Vec2i coordIndx = getIndexesByCoords((entity.lock())->pos);
    getCell(coordIndx.x, coordIndx.y)->entities.push_back(entity);
}

void EntityContainerMap::removeEntityFromCell(EntityPtr entity)
{
	Vec2i coordIndx = getIndexesByCoords((entity.lock())->pos);
	// @todo: define foreach entities!
    Entities& entities = getEntitiesFromCell(coordIndx.x, coordIndx.y);
	
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
    implementForEachCell([](MapCell*cell)
    {
        RemoveDeletedObjectsFromContainer(cell->entities);
    });
}

Entities& EntityContainerMap::getEntitiesFromCell(float x, float y)
{
	Vec2i cell_coords = getIndexesByCoords(x, y);
	return getEntitiesFromCell(cell_coords.x, cell_coords.y);
}

Entities& EntityContainerMap::getEntitiesFromCell(int x, int y)
{
	return getCell(x, y)->entities;
}

