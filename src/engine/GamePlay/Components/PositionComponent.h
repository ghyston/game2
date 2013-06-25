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
	
	int get_id() { return ComponentsType::POSITION_COMPONENT; }
	
	Vec2f position;
};

#endif	/* POSITIONCOMPONENT_H */