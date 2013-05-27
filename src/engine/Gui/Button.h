/* 
 * File:   Button.h
 * Author: Hyston
 *
 * Created on 12 Май 2013 г., 9:36
 */

#ifndef __BUTTON_H__
#define	__BUTTON_H__

#include "Widget.h"
#include "../Common/Color3f.h"

class Button : public Widget
{
protected: 
		
	float width;
	float height;
	
	virtual void setup_vertexes();
	
public:
	
	Color3f color_idle;
	Color3f color_pressed;
	
	Button(Vec2f pos, Vec2f size) : Widget()
	{	
		coords = pos;
		width = size.x;
		height = size.y;
		setup_vertexes();		
	}
	
	virtual bool is_touched(float x, float y);
	
	virtual void on_touch();
	
	virtual void on_release();
		
};

#endif	/* BUTTON_H */

