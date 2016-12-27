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
#include "core/Components.h"

class BaseSystem
{
public:
	
	void process(EntityPtr entity);
	
	virtual void pre_step() {;}
	virtual void post_step() {;}
	
protected:
	
	virtual void update(EntityPtr entity) = 0;
	
};

#endif	/* __BASESYSTEM_H__ */

