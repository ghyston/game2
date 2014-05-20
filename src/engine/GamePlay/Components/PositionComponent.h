/* 
 * File:   PositionComponent.h
 * Author: Hyston
 *
 * Created on 23 Июнь 2013 г., 9:56
 */

#ifndef POSITIONCOMPONENT_H
#define	POSITIONCOMPONENT_H

#include "../../Common/Vector2f.h"

class PositionComponent : public IComponent
{
public:
	
	static int GetTypeImpl() { return ComponentsType::POSITION_COMPONENT; }
	
	Vec2f position;
	Vec2f old_position; //Just 4 optimisation.
};

#endif	/* POSITIONCOMPONENT_H */