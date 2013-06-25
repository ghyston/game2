/* 
 * File:   Components.h
 * Author: Hyston
 *
 * Created on 17 Июнь 2013 г., 16:46
 */

#ifndef __COMPONENTS_H__
#define	__COMPONENTS_H__

struct ComponentsType
{
	enum Enum
	{
		__INVALID = -1,
		__FIRST = 0,
		POSITION_COMPONENT = __FIRST,
		RENDER_COMPONENT,
		MOVEMENT_COMPONENT,
		__COUNT
	};
};

#include "Components/MovementComponent.h"
#include "Components/PositionComponent.h"
#include "Components/RenderComponent.h"

#endif	/* COMPONENTS_H */

