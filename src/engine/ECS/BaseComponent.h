#ifndef __BASECOMPONENT_H__
#define __BASECOMPONENT_H__


/**
 * Common interface for all components.
 */

class IComponent
{
	
public:
	
	IComponent() {;}

	template <class ConcreteComponentType>
	static int GetType() { return ConcreteComponentType::GetTypeImpl(); }
	
	virtual ~IComponent() {;}

};

#endif //__BASECOMPONENT_H__