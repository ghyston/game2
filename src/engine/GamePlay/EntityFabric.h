/* 
 * File:   EntityFabric.h
 * Author: Hyston
 *
 * Created on 24 Июнь 2013 г., 16:48
 */

#ifndef __ENTITYFABRIC_H__
#define	__ENTITYFABRIC_H__

#include "../Common/Vector2f.h"
#include "Components.h"
#include "../ECS/Entity.h"

class EntityFabric
{
public:
	
	static Entity * get_tower(Vec2f coords);
    
    static Entity * get_connector(Entity * tower_1, Entity * tower_2);
	
};



#endif	/* ENTITYFABRIC_H */

