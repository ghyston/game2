/* 
 * File:   TouchManager.h
 * Author: Hyston
 *
 * Created on 30 Май 2013 г., 13:41
 */

#ifndef __TOUCHMANAGER_H__
#define	__TOUCHMANAGER_H__

#include <vector>
#include "../Common/ThreadLock.h"
#include "TouchEvent.h"
#include "BaseTouchProcessor.h"

class TouchManager
{
private:
	//TODO: 10 is max supported fingers
	std::vector<BaseTouchProcessor*> processors;
	
	std::vector<TouchEvent> touch_events;
	
	bool is_processed;
	
	MyCThreadLock mutex;
	
public:
	
	void process();
	
	void push_event(const TouchEvent& touch_event);
	
	TouchManager() : 
		processors(100), is_processed(false)
	{;}
	
	static Vec2f translateCoordsDevToSpace(Vec2f device_coords);
	
protected:	
	
	void process(TouchEvent& touch_event);
	
	BaseTouchProcessor* ChooseProcessor(Vec2f coords);

};

#endif	/* __TOUCHMANAGER_H__ */

