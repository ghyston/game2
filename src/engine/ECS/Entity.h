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
#include <typeinfo>
//#include "../Common/Obj.h"
#include "BaseComponent.h"
#include "Types.h"

using namespace std;

#define GetCmpt(type,name,entity) type* name = entity->get_component<type>();
#define HasCmpt(type,entity) entity->has_component<type>()

class Entity/* : public Obj*/
{
public:
	
	static weak_ptr<Entity> create();
	
	template <class T>
	void add_component(T* component)
	{
		components[IComponent::GetType<T>()] = (IComponent*)component;
	}
	
	template <typename T>
	T* get_component()
	{
		return (T*)components[IComponent::GetType<T>()];
	}
	
	template <typename T>
	bool has_component()
	{
		return (components.count(IComponent::GetType<T>()) > 0);
	}

	template <typename T>
	void remove_component()
	{
		delete components[T::GetType()];
		components.erase(T::GetType());
	}
	
	void clear();
	
	void mark_deleted();
	
	virtual ~Entity();
	
private:
	
	// New entities should be created throw create();
	Entity();
    
    Entity(const Entity &) = delete;
    const Entity &operator =(const Entity &) = delete;
		
	// Entity components.
	std::map<size_t, IComponent*> components;
	
	std::shared_ptr<Entity> _self; //dump way to keep counter. @todo: change it
	
};

#endif	/* __ENTITY_H__ */

