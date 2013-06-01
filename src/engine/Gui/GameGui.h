/* 
 * File:   GameGui.h
 * Author: Hyston
 *
 * Created on 12 Май 2013 г., 9:32
 */

#ifndef __GAMEGUI_H__
#define	__GAMEGUI_H__

#include "Button.h"

class GameGui
{
private:
	
	std::vector<Widget*> widgets;
	
	std::vector<Widget*>::iterator widget_iter;
	
public:
	
	GameGui();
	
	void draw_gui();
	
	
	//Widget* get_next_widget();
	
	//TODO: this is just for test only!
	Widget* get_first_widget();
	
	void reset_widget_iterator();
	
	//Find widget at (x,y) and touch them.
	Widget* on_touch(Vec2f coords);
	
};



#endif	/* GAMEGUI_H */

