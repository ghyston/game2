/* 
 * File:   Entity.h
 * Author: Hyston
 *
 * Created on 17 Июнь 2013 г., 16:40
 */

#ifndef __ENTITY_H__
#define	__ENTITY_H__

#include <map>
#include <vector>
#include "../Common/Obj.h"
#include "BaseComponent.h"

#define GetCmpt(type,name,entity) type* name = entity->get_component<type>();
#define HasCmpt(type,entity) entity->has_component<type>()

class Entity : public Obj
{
public:
	
	// @todo: move to EntityFabric!
	struct Types
	{
		enum Enum
		{
			TOWER,
			ENERGY,
			CONNECT
		};
	};
	
	Types::Enum type;
	
	static Entity * create();
	
	template <typename T>
	void add_component(T* component)
	{
		components[typeid(T).hash_code()] = (IComponent*)component;
	}
	
	template <typename T>
	T* get_component()
	{
		return (T*)components[typeid(T).hash_code()];
	}
	
	template <typename T>
	bool has_component()
	{
		return (components.count(typeid(T).hash_code()) > 0);
	}

	template <typename T>
	void remove_component()
	{
		delete components[typeid(T).hash_code()];
		components.erase(typeid(T).hash_code());
	}
	
	void clear();
	
private:
	
	// New entities should be created throw create();
	Entity();
		
	// Entity components.
	std::map<size_t, IComponent*> components;
	
};

#endif	/* __ENTITY_H__ */

