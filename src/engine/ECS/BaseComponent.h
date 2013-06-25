#ifndef __BASECOMPONENT_H__
#define __BASECOMPONENT_H__

class IComponent
{
protected:
	
	//int id;
	//bool deleted;
	
public:
	
	IComponent()// : 
		//deleted(false)
	//	id(ComponentsType::__INVALID)
		{;}
		
	virtual int get_id() = 0;
	
	//void mark_deleted() { deleted = true; }
	
	//bool is_deleted() { return deleted; }
};

#endif //__BASECOMPONENT_H__