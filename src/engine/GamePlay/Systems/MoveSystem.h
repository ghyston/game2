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


class MoveSystem : public BaseSystem
{
private:
	PositionComponent* position_com;
	MovementComponent* move_com;
	
public:
		
	void update(Entity * entity);
	
};

#endif	/* __MOVESYSTEM_H__ */

