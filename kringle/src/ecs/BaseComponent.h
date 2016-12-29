#ifndef __BASECOMPONENT_H__
#define __BASECOMPONENT_H__


/**
 * Common interface for all components.
 */

class IComponent
{
	
public:

	template <class ConcreteComponentType>
	static int GetType() { return ConcreteComponentType::GetTypeImpl(); }
    
protected:
    
    IComponent() {;}
    virtual ~IComponent() {;}
    
    friend class Entity;

};

#endif //__BASECOMPONENT_H__
