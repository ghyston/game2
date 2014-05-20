/* 
 * File:   MoveSystem.h
 * Author: Hyston
 *
 * Created on 23 Июнь 2013 г., 5:39
 */

#ifndef __MOVESYSTEM_H__
#define	__MOVESYSTEM_H__

#include "../../ECS/BaseSystem.h"
#include "../../Timer.h"
#include "../../GameEngine.h"
#include <stack>


class MoveSystem : public BaseSystem
{
	
protected:
	
	virtual void pre_step();
		
	virtual void update(EntityPtr entity);
	
	virtual void post_step();
	
private:
	
	Entities moved_entities;
	
};

#endif	/* __MOVESYSTEM_H__ */

