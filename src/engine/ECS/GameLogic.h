/*
 * File:   GameLogic.h
 * Author: Hyston
 *
 * Created on 17 Июнь 2013 г., 16:29
 */

#ifndef __GAMELOGIC_H__
#define	__GAMELOGIC_H__

#include <vector>
#include <list>

#include "../Common/ShrPtr.h"

#include "Entity.h"
#include "BaseSystem.h"
#include "Map.h"

class GameLogic
{
public:

	virtual void start() {;}
	virtual void step();
	virtual void stop() {;}
	
	virtual void add_system(BaseSystem * system);
	virtual void add_entity(EntityPtr entity);
		
	Entities& get_unpositioned_entities() { return entities; }
	Entities& get_entities_by_coords(Vec2f& pos);
	
protected:
	
	std::vector<BaseSystem*> systems;
	Entities entities; //unpositioned entities.

	Map map;
};

#endif	/* __GAMELOGIC_H__ */

