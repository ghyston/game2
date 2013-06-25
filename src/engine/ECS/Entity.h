/* 
 * File:   Entity.h
 * Author: Hyston
 *
 * Created on 17 Июнь 2013 г., 16:40
 */

#ifndef __ENTITY_H__
#define	__ENTITY_H__

#include <map>
#include "../GamePlay/Components.h"

class Entity
{
public:
	
	Entity();
	
	std::map<int, IComponent*> components;
	
	void add_component(int component_id, IComponent* component);
	
	IComponent* get_component(int component_id);
	
	bool has_component(int component_id);
	
	void clear();
};

#endif	/* __ENTITY_H__ */

