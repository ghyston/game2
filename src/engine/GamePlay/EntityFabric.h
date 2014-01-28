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
#include "../ECS/Types.h"

class EntityFabric
{
public:
	// @todo: rename to create!
	static EntityPtr get_tower(EntityPtr parent, Vec2f coords);
    
    static EntityPtr get_connector(EntityPtr tower_1, EntityPtr tower_2);
	
	static EntityPtr create_energy(Vec2f coords);
	
	static EntityPtr create_energy_generator(Vec2f coords, float rad, float intensivity);
		
};



#endif	/* ENTITYFABRIC_H */

