/* 
 * File:   TouchEvent.h
 * Author: Hyston
 *
 * Created on 30 Май 2013 г., 14:07
 */

#ifndef __TOUCHEVENT_H__
#define	__TOUCHEVENT_H__

#include "../Common/Vector2f.h"

struct TouchEvent
{
	short id;
	Vec2f coords;
	enum Enum
	{
		ACTION_DOWN,
		ACTION_MOVE,
		ACTION_UP
	} type;
};


#endif	/* __TOUCHEVENT_H__ */

