/* 
 * File:   CollisionSystem.h
 * Author: Hyston
 *
 * Created on 24 Июнь 2013 г., 17:34
 */

#ifndef __COLLISIONSYSTEM_H__
#define	__COLLISIONSYSTEM_H__

#include "../../ECS/BaseSystem.h"

class CollisionSystem : public BaseSystem
{
	private:
		PositionComponent * position_com;
		MovementComponent * move_com;
		
	public:
		
		void update(Entity * entity);
};

#endif	/* COLLISIONSYSTEM_H */
