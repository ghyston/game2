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
	
	std::vector<BaseSystem*> systems;
	
	std::vector<Entity*> entities;
	
	void start();
	
	void step();
	
	void stop();
	
	void add_system(BaseSystem * system)
	{
		systems.push_back(system);
	}
	
	void add_entity(Entity * entity)
	{
		entities.push_back(entity);
	}
	
	void remove_entity(Entity * entity)
	{
		// @todo: removing all systems/entities correctly!
	}
	
	
	
};

#endif	/* __GAMELOGIC_H__ */

