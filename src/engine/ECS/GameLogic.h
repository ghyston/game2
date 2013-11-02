/* 
 * File:   GameLogic.h
 * Author: Hyston
 *
 * Created on 17 Июнь 2013 г., 16:29
 */

#ifndef __GAMELOGIC_H__
#define	__GAMELOGIC_H__

#include <vector>

#include "Entity.h"
#include "BaseSystem.h"

class GameLogic
{
public:
	
	typedef std::map<size_t, Entity*>::iterator EntityIt;
	
	std::vector<BaseSystem*> systems;
	
//	std::vector<Entity*> entities;
	std::map<size_t, Entity*> entities;
	
	void start();
	
	void step();
	
	void stop();
	
	void add_system(BaseSystem * system);
	
	void add_entity(Entity * entity);
	
	// Mark entity as deleted.
	void remove_entity(Entity * entity);
	
	// Mark entity as deleted.
	// @note: Prefer to call by pointer, not by id!
	void remove_entity(size_t entity_id);
	
private:
	
	void erase_removed_entities();
	
};

#endif	/* __GAMELOGIC_H__ */

