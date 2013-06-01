/* 
 * File:   TouchManager.h
 * Author: Hyston
 *
 * Created on 30 Май 2013 г., 13:41
 */

#ifndef __TOUCHMANAGER_H__
#define	__TOUCHMANAGER_H__

#include "TouchEvent.h"
#include "BaseTouchProcessor.h"
#include <vector>

class TouchManager
{
private:
	//TODO: 10 is max supported fingers
	std::vector<BaseTouchProcessor*> processors;
	
public:
	
	TouchManager() : processors(10) {;}
	
	void process(TouchEvent& touch_event);
	
	static Vec2f translateCoordsDevToSpace(Vec2f device_coords);
	
protected:	
	
	BaseTouchProcessor* ChooseProcessor(Vec2f coords);

};

#endif	/* __TOUCHMANAGER_H__ */

