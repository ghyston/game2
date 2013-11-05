/* 
 * File:   RectRenderable.h
 * Author: Hyston
 *
 * Created on 30 Май 2013 г., 12:22
 */

#ifndef __RECTRENDERABLE_H__
#define	__RECTRENDERABLE_H__

#include "BaseRenderable.h"

class RectRenderable : public BaseRenderable
{
protected:
	float width;
	float height;

public:

	RectRenderable(float _width, float _height) :
	width(_width), height(_height)
	{
		;
	}

	virtual void setup_vertexes();
	
	//@note: call setup_vertexes() after that!
	void set_height(float height) { this->height = height; }
	//@note: call setup_vertexes() after that!
	void set_width(float width) { this->width = width; }

private:
};

#endif	/* __RECTRENDERABLE_H__ */

