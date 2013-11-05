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

// @todo: make entities a vector!
// @todo: may be make file with all types?
typedef std::map<size_t, Entity*> Entities;
typedef Entities::iterator EntityIt;

class GameLogic
{
public:

	virtual void start() {;}
	virtual void step();
	virtual void stop() {;}
	
	virtual void add_system(BaseSystem * system);
	virtual void add_entity(Entity * entity);
	
	// @note: it just mark note as delete, actual remove is after step()
	virtual void remove_entity(Entity * entity);
	
	// @note: Prefer to call by pointer, not by id!
	virtual void remove_entity(size_t entity_id);
	
	Entities& get_entities() { return entities; }
	
protected:
	
	std::vector<BaseSystem*> systems;
	Entities entities;
	void erase_removed_entities();
	
};

#endif	/* __GAMELOGIC_H__ */

