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
#include "../GamePlay/Components.h"
#include "RefEntity.h"

class Entity
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
	
	size_t get_id() { return this->id; }
	
	void mark_deleted();	
	bool is_deleted() { return deleted_mark; }
	
	void register_listener(RefEntity * ref);
	void unregister_listener(RefEntity * ref);

	
private:
	
	// New entities should be created throw create();
	Entity();
	
	//@todo: do we need id?
	static size_t first_unused_id;
	
	// Unique entity id.
	size_t id;
	
	void set_id(size_t id) { this->id = id; }
	
	// Entity components.
	std::map<size_t, IComponent*> components;
	
	bool deleted_mark;
	
	// listeners
	std::vector<RefEntity*> waitors;

};

#endif	/* __ENTITY_H__ */

