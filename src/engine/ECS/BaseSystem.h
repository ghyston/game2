/* 
 * File:   BaseSystem.h
 * Author: Hyston
 *
 * Created on 17 Июнь 2013 г., 16:57
 */

#ifndef __BASESYSTEM_H__
#define	__BASESYSTEM_H__

#include <vector>
#include "Entity.h"
#include "../GamePlay/Components.h"

class BaseSystem
{
public:
	
	std::vector<int> components_types;
	
	virtual void update(Entity * entity) = 0;
	
	bool check_components(Entity * entity);
	
	void process(Entity * entity);
};

#endif	/* __BASESYSTEM_H__ */

