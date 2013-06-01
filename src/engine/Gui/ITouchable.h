/* 
 * File:   ITouchable.h
 * Author: Hyston
 *
 * Created on 30 Май 2013 г., 17:08
 */

#ifndef __ITOUCHABLE_H__
#define	__ITOUCHABLE_H__

#include "../Common/Vector2f.h"

class ITouchable
{
public:
	virtual bool is_touched(Vec2f touch_coords) = 0;
};

#endif	/* __ITOUCHABLE_H__ */

