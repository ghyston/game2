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

//@todo: rename this and PassMap to EntityGrid and PassGrid!
class EntityContainerMap : public BaseGridMap<MapCell>
{
public:
	
	void addEntity(float pos_x, float pos_y, EntityPtr entity);
	void removeEntityFromCell(float pos_x, float pos_y, EntityPtr entity);
	
	void checkFroRemovedEntities();
	
	Entities& getEntitiesFromCell(float x, float y);
	Entities& getEntitiesFromCell(int x, int y);
};

#endif /* defined(__Game2__EntityContainerMap__) */
