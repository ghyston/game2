/* 
 * File:   EntityFabric.h
 * Author: Hyston
 *
 * Created on 24 Июнь 2013 г., 16:48
 */

#ifndef __ENTITYFABRIC_H__
#define	__ENTITYFABRIC_H__

#include "../Common/Vector2f.h"
#include "../ECS/Entity.h"
#include "Components.h"

class EntityFabric
{
public:
	
	static Entity * get_tower(Vec2f coords);
	
};



#endif	/* ENTITYFABRIC_H */

