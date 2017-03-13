//
//  EntityContainerMap.h
//  Game2
//
//  Created by Stepanov Ilia on 17/05/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__EntityContainerMap__
#define __Game2__EntityContainerMap__

#include "BaseGridMap.h"
#include "MapCell.h"
#include "../Common/VecShrPtr.h"

class EntityContainerMap : public BaseGridMap<MapCell>
{
public:
    
    static EntityContainerMap * create(int width, int height, float cellSize)
    {
        auto map = new EntityContainerMap();
        map->init(width, height, cellSize);
        return map;
    }
	
	void addEntity(EntityPtr entity);
	void removeEntityFromCell(EntityPtr entity);
	
	void checkFroRemovedEntities();
	
	Entities& getEntitiesFromCell(float x, float y);
	Entities& getEntitiesFromCell(int x, int y);
	
};

#endif /* defined(__Game2__EntityContainerMap__) */
