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
	// @todo: rename to create!
	static Entity * get_tower(Entity* parent, Vec2f coords);
    
    static Entity * get_connector(Entity * tower_1, Entity * tower_2);
	
	static Entity * create_energy(Vec2f coords);
	
	static Entity * create_energy_generator(Vec2f coords, float rad, float intensivity);
		
};



#endif	/* ENTITYFABRIC_H */

