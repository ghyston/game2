/* 
 * File:   TouchController.h
 * Author: Hyston
 *
 * Created on 20 Май 2013 г., 15:52
 */

#ifndef __TOUCHCONTROLLER_H__
#define	__TOUCHCONTROLLER_H__

#include "../Common/Vector2f.h"
#include "Widget.h"

class TouchController
{
private:
	
	Widget* touched_widget;
	Vec2f touched_point;
	
	enum TouchStates
	{
		Idle,
		WidgetDragged,
		MapDragged
	} state;
	
public:
	
	TouchController()
	{
		touched_widget = NULL;
		state = Idle;
	}
	
	bool process_down(float x, float y);
	
	bool process_move(float x, float y);
	
	bool process_up(float x, float y);
	
private:
	
	Vec2f translateCoordsDevToSpace(Vec2f device_coords);
};


#endif	/* __TOUCHCONTROLLER_H__ */

