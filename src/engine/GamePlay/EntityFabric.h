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

#include <vector>

class EntityFabric
{
public:
	// @todo: rename to create!
	static EntityPtr get_tower(EntityPtr parent, Vec2f coords);
    
    static EntityPtr get_connector(EntityPtr tower_1, EntityPtr tower_2);
	
	static EntityPtr create_energy(Vec2f coords);
	
	static EntityPtr create_energy_generator(Vec2f coords, float rad, float intensivity);
		
	static EntityPtr CreateUnit(Vec2f coords);
	
	static EntityPtr CreateWaypoint(Vec2f coords);
	
	static EntityPtr CreateHindernis(Vec2f coords, std::vector<Vec2f> points);
	
private:
	
	static void BlockCellsByPolygon(Vec2f coords, const std::vector<Vec2f>& points, EntityPtr polygon);
};



#endif	/* ENTITYFABRIC_H */

