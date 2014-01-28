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

class GameLogic
{
public:

	virtual void start() {;}
	virtual void step();
	virtual void stop() {;}
	
	virtual void add_system(BaseSystem * system);
	virtual void add_entity(EntityPtr entity);
	
	// @note: it just mark note as delete, actual remove is after step()
	virtual void remove_entity(Entity * entity);
	
	Entities& get_entities() { return entities; }
	
protected:
	
	std::vector<BaseSystem*> systems;
	Entities entities;
	
};

#endif	/* __GAMELOGIC_H__ */

