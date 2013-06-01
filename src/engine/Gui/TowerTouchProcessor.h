/* 
 * File:   TowerTouchProcessor.h
 * Author: Hyston
 *
 * Created on 30 Май 2013 г., 13:57
 */

#ifndef __TOWERTOUCHPROCESSOR_H__
#define	__TOWERTOUCHPROCESSOR_H__

#include "BaseTouchProcessor.h"
#include "TouchManager.h"
#include "../GamePlay/BaseTower.h"

class TowerTouchProcessor : public BaseTouchProcessor
{
public:

	TowerTouchProcessor(BaseTower* touched_tower) :
	tower(touched_tower)
	{
		;
	}
	
	virtual Vec2f translate_coords(Vec2f device_coords);

private:

	BaseTower* tower;

protected:
	virtual void process_down(Vec2f coords);

	virtual void process_move(Vec2f coords);

	virtual void process_up(Vec2f coords);
};

#endif	/* TOWERTOUCHPROCESSOR_H */

