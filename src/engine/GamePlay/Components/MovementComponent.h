/* 
 * File:   MovementComponent.h
 * Author: Hyston
 *
 * Created on 23 Июнь 2013 г., 9:54
 */

#ifndef __MOVEMENTCOMPONENT_H__
#define	__MOVEMENTCOMPONENT_H__

#include "../../Common/Vector2f.h"
#include "../../ECS/BaseComponent.h"

class MovementComponent : public IComponent
{
public:
	
	static int GetTypeImpl() { return ComponentsType::MOVEMENT_COMPONENT; }

	Vec2f speed;
	
	Vec2f velocity;
	
};

#endif	/* __MOVEMENTCOMPONENT_H__ */

