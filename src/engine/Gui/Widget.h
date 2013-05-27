#ifndef __WIDGET_H__
#define __WIDGET_H__

#include "../Renderer/BaseRenderable.h"
#include <vector>

class Widget : public BaseRenderable
{
public:
	
	Widget() : BaseRenderable() {}
	
	virtual bool is_touched(float x, float y) = 0;
	
	virtual void on_touch() = 0;
	
	virtual void on_release() = 0;
	
	//std::vector<Widget *> children;
	
	//Widget * parent;
		
};

#endif //__WIDGET_H__