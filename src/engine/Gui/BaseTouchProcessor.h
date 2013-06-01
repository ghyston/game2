/* 
 * File:   BaseTouchProcessor.h
 * Author: Hyston
 *
 * Created on 30 Май 2013 г., 13:55
 */

#ifndef __BASETOUCHPROCESSOR_H__
#define	__BASETOUCHPROCESSOR_H__

#include "TouchEvent.h"
#include "../Common/Vector2f.h"

class BaseTouchProcessor
{
public:
	virtual void process(TouchEvent& event);
	
	virtual Vec2f translate_coords(Vec2f device_coords) = 0;
	
protected:
	
	virtual void process_down(Vec2f coords) = 0;
	
	virtual void process_move(Vec2f coords) = 0;
	
	virtual void process_up(Vec2f coords) = 0;

};

#endif	/* __BASETOUCHPROCESSOR_H__ */

